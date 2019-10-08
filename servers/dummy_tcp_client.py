
import socket

IP = 'localhost'
PORT = 8956
BUFF_SIZE = 1024


sock = socket.socket()
sock.connect((IP, PORT))

while True:
    sock.send(input().encode())
    print(sock.recv(BUFF_SIZE).decode())
