
import socket

IP = '0.0.0.0'  # IPv4
PORT = 8956
BUFF_SIZE = 1024

sock = socket.socket()
sock.bind((IP, PORT))
sock.listen(True)

print(f'Server started {IP}:{PORT}')

while True:
    conn, addr = sock.accept()
    print(f'Client connected {addr}')

    while True:
        data = conn.recv(BUFF_SIZE)
        print(f'Received: {data.decode()}')

        to_send = input().encode()
        conn.send(to_send)
