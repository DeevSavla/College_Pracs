import './App.css';
import useCustomHook from './customHook';
function App() {
  const [count, { increment, decrement, reset }] = useCustomHook(0);
  return (
    <div>

      <div>
        <h1>{count}</h1>
      </div>

      <div>
        <button id='increment' onClick={increment}>Increment</button>
        <button id='decrement' onClick={decrement}>Decrement</button>
        <button id='reset' onClick={reset}>Reset</button>
      </div>
    </div>
  );
}

export default App;



import { useState } from 'react';

const useCustomHook = (initialCount) => {
  const [count, setCount] = useState(initialCount);
  const increment = () => setCount((prevCount) => prevCount + 1);
  const decrement = () => setCount((prevCount) => prevCount - 1);
  const reset = () => setCount(0);
  return [count, { increment, decrement, reset }];
};

export default useCustomHook;
