
import socket

IP = 'localhost'
PORT = 8956
BUFF_SIZE = 1024


sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)


while True:
    sock.sendto(input().encode(), (IP, PORT))
    data, addr = sock.recvfrom(BUFF_SIZE)
    print(f'<{addr}>: {data.decode()}')
