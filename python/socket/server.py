#!/usr/bin/env python

import socket

def run():

    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind((socket.gethostname(), 8000))

    max_connect_request = 5
    server_socket.listen(max_connect_request)

    while True:
        client_socket, address = server_socket.accept()
if __name__ == "__main__":

    run()
