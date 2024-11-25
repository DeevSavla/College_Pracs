import socket
import time

HOST='127.0.0.1'
PORT=5001

client_socket=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
client_socket.connect((HOST,PORT))

while True:
    message=input("enter the data here..")
    client_socket.sendall(message.encode())

    if message=='end':
        print("the connection has ended ")
        break
    
    data=client_socket.recv(1024).decode()

    if data == 'ACK':
        print(f"Acknowledgment received for {message}.")
        time.sleep(1)
    
    else:
        while data=='NACK':
            print(f"not received acknowledgement {message}")
            print(f"resending {message}")
            client_socket.send(message.encode())
            data=client_socket.recv(1024).decode()
            time.sleep(1)
        print(f"received acknowledgement for {data}")
    
print("ended the connection")
client_socket.close()