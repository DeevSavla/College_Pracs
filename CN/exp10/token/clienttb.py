import socket

HOST="127.0.0.1"
PORT=5001

client_socket=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
client_socket.connect((HOST,PORT))

while True:
    msg=input("enter your message: ")
    client_socket.sendall(msg.encode())
    if(msg=="end"):
        break
    
print("end")
client_socket.close()