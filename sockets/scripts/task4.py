#!/usr/bin/python3

import socket

def handle_connection(client_socket):
    # Receive data from the client
    data = client_socket.recv(1024).decode('utf-8')

    # Print the client's IP address
    client_address = client_socket.getpeername()
    print(f"Client connected: {client_address[0]}")

    print(vars(data))

    # Send a response (HTTP 200 OK)
    response = "HTTP/1.1 200 OK\r\n\r\n"

    client_socket.send(response.encode('utf-8'))
    client_socket.close()

server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server_socket.bind(('0.0.0.0', 8080))
server_socket.listen(5)
print("Server listening on port 8080")

while True:
    client_socket, addr = server_socket.accept()
    handle_connection(client_socket)

