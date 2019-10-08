
import socket

IP = '0.0.0.0'
PORT = 8956
BUFF_SIZE = 1024

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((IP, PORT))


while True:
    data, addr = sock.recvfrom(BUFF_SIZE)
    print(f'<{addr}> Received: {data.decode()}')

    to_send = data.capitalize()
    sock.sendto(to_send, addr)
