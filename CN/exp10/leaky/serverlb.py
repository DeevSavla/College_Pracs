import socket
import threading
import time

HOST="127.0.0.1"
PORT=5001
MAX_SIZE=5
LEAK_RATE=2

server_socket=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
server_socket.bind((HOST,PORT))
server_socket.listen()

print(f"server socket is listening on {HOST}:{PORT}...")
conn,addr=server_socket.accept()
print(f"connected by {addr}")

received_data=[]

def leaky():
    while True:
        time.sleep(LEAK_RATE)
        if received_data:
            leaked_data=received_data.pop(0)
            print(f"the leaked data is {leaked_data}")
        else:
            print(f"there is no data to leak that means that the bucket is empty")

def AddtoQueue():
    with conn:
        while True:
            data=conn.recv(1024)
            if not data or data.decode()=="end":
                if len(received_data)>0:
                    print(f"the remaining data in the bucket is {received_data}")
                print("the connection is ended by the client ")
                break
            if len(received_data)<MAX_SIZE:
                received_data.append(data.decode())
                print(f"the received data is {received_data}")
            else:
                print("the bucket is now full so this data will be discarded")
                
leaky_thread=threading.Thread(target=leaky,daemon=True)
leaky_thread.start()

AddtoQueue()
server_socket.close()