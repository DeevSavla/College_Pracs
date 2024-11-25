import socket

HOST="127.0.0.1"
PORT=5001

client_socket=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
client_socket.connect((HOST,PORT))

while True:
    msg=input("enter the message here: ")
    client_socket.sendall(msg.encode())
    if msg=="end":
        break
    
print("END")
client_socket.close()