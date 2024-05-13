import { useState } from 'react';
import './App.css';

function App() {
  const [cart, setCart] = useState([]);
  const [name, setName] = useState('');
  const [number, setNumber] = useState('');
  const [price, setPrice] = useState('');

  function nameChange(e) {
    setName(e.target.value);
  }

  function numberChange(e) {
    setNumber(e.target.value);
  }

  function priceChange(e) {
    setPrice(e.target.value);
  }

  function addToCart() {
    setCart([...cart, { id: number, name: name, price: price }]);
    setNumber('');
    setPrice('');
    setName('');
  }

  const handleDeleteTodo = (id) => {
    const updateList = cart.filter((item) => item.id !== id);
    setCart(updateList);
  };

  return (
    <>
      <h1>Shopping Cart</h1>
      <label>Give Product No:</label>
      <input type="text" value={number} onChange={numberChange} />
      <br></br>
      <label>Give Name of Product:</label>
      <input type="text" value={name} onChange={nameChange} />
      <br></br>
      <label>Give Price:</label>
      <input type="number" value={price} onChange={priceChange} />
      <br></br>
      <button type="button" onClick={addToCart}>Add to Cart</button>
      <ul>
        {cart.map((item) => (
          <li key={item.id}>
            {item.name} - {item.price}
            <button onClick={() => handleDeleteTodo(item.id)}>Delete</button>
          </li>
        ))}
      </ul>
    </>
  );
}

export default App;
