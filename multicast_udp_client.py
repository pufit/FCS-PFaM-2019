import socket


BUFF_SIZE = 1024
MCAST_GRP = '224.1.1.1'
MCAST_PORT = 5007

MULTICAST_TTL = 2

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, socket.IPPROTO_UDP)
sock.setsockopt(socket.IPPROTO_IP, socket.IP_MULTICAST_TTL, MULTICAST_TTL)

while True:
    sock.sendto(input().encode(), (MCAST_GRP, MCAST_PORT))
    data, addr = sock.recvfrom(BUFF_SIZE)
    print(f'<{addr}>: {data.decode()}')
