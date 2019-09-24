
import socket

IP = '0.0.0.0'
PORT = 8956
BUFF_SIZE = 1024

sock = socket.socket()

sock.setblocking(False)

sock.bind((IP, PORT))
sock.listen(True)


print(f'Server started {IP}:{PORT}')

connections = []


while True:
    try:
        conn, addr = sock.accept()
        print(f'Client connected {addr}')
        connections.append((conn, addr))

    except BlockingIOError:
        for conn, addr in connections:
            try:
                data = conn.recv(BUFF_SIZE)
                print(f'<{addr}> Received: {data.decode()}')

                to_send = data.capitalize()
                conn.send(to_send)
            except BlockingIOError:
                pass
            except ConnectionResetError:
                connections.remove((conn, addr))
