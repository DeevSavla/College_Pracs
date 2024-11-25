import socket
import threading
import time

HOST='127.0.0.1'
PORT=5001
MAX_SIZE=5
LEAK_RATE=2

server_socket=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
server_socket.bind((HOST,PORT))
server_socket.listen()

print(f"the server socket is listening on: {HOST}:{PORT}...")
conn,addr=server_socket.accept()
print(f"connected by {addr} ")

tokens=[]
incoming_data=[]
token_lock=threading.Lock()

def generate_tokens():
    while True:
        with token_lock:
            if (len(tokens)<MAX_SIZE):
                tokens.append('*')
            else:
                print(f"the bucktet is full.. ")
        time.sleep(LEAK_RATE)

def Data():
    with conn:
        while True:
            data=conn.recv(1024)
            if not data or data.decode()=="end":
                if len(tokens)>0:
                    print(f"the remaining data is: {incoming_data}")
                print("the communication is ended by the client..")
                break
            with token_lock:
                if len(tokens)!=0:
                    incoming_data.append(data.decode())
                    tokens.pop(0)
                    print(f"the incoming data is: {incoming_data}")
                else:
                    print("not enough tokens in the bucket so discarding the incoming data.. ")

token_thread=threading.Thread(target=generate_tokens,daemon=True)
token_thread.start()

Data()
server_socket.close()