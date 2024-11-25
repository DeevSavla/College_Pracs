import socket
import threading
import time

HOST='127.0.0.1'
PORT=5001
MAX_SIZE=5

server_socket=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
server_socket.bind((HOST,PORT))
server_socket.listen()

conn,addr=server_socket.accept()

tokens=[]
received_data=[]

def Leaky():
    while True:
        time.sleep(3)
        if received_data:
            leaked_data=received_data.pop(0)
            print(f"the leaked data is {leaked_data}")
        else:
            print("nothing there to leak so it is empty")

def generate_tokens():
    while True:
        if (len(tokens)<MAX_SIZE):
            tokens.append('*')
            print(f"the token bucket looks like this: {tokens}")
        else:
            print(f"the bucktet is full.. ")
        time.sleep(1)

def Data():
    with conn:
        while True:
            data=conn.recv(1024).decode()
            if not data or data=="end":
                if len(tokens)>0:
                    print(f"the remaining tokems is: {tokens}")
                print("the communication is ended by the client..")
                break
            if len(tokens)>0:
                tokens.pop(0)
                received_data.append(data)
                print(f"bucket contains this data: {received_data}")
            else:
                print("token bucket is empty discarding the data..")

token_thread=threading.Thread(target=generate_tokens,daemon=True)
token_thread.start()

leaky_thread=threading.Thread(target=Leaky,daemon=True)
leaky_thread.start()

Data()
server_socket.close()