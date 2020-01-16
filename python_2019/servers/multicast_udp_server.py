import socket
import struct

BUFF_SIZE = 1024
MCAST_GRP = '228.0.0.5'
MCAST_PORT = 5007


sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, socket.IPPROTO_UDP)
sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

sock.bind(('', MCAST_PORT))

mreq = struct.pack("4sl", socket.inet_aton(MCAST_GRP), socket.INADDR_ANY)
sock.setsockopt(socket.IPPROTO_IP, socket.IP_ADD_MEMBERSHIP, mreq)

while True:
    data, addr = sock.recvfrom(BUFF_SIZE)
    print(f'<{addr}> Received: {data.decode()}')

    to_send = data.capitalize()
    sock.sendto(to_send, addr)
