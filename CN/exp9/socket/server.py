import socket
import time
import random 

HOST='127.0.0.1'
PORT=5001

server_socket=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
server_socket.bind((HOST,PORT))
server_socket.listen()

print(f"the server is listening on {HOST}:{PORT}")
conn,addr=server_socket.accept()
print(f"connected by {addr}")


with conn:
    while True:
        data=conn.recv(1024).decode()
        if not data:
            break
        if data=='end':
            print("the connection is ended by the client ")
            break
        if random.choice([True,False]):
            print(f"received data {data}")
            message='ACK'
            conn.send(message.encode())
            time.sleep(1)
        else:
            print("lost packets")
            message='NACK'
            conn.send(message.encode())
            time.sleep(1)
            
server_socket.close()
