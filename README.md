# Multithreaded Chat Application

It is a multithreaded client/server ChatServer based on console which uses C++ Socket programming. A server listens for connection requests from clients across the network or even from the same machine. Clients know how to connect to the server via an IP address and port number. After connecting to the server, the client gets to choose his/her username on the chat room. The client sends a message, the message is sent to the server. After receiving the message from the client, the server broadcasts the message if it is not a private message. And if it is a private message which is detect using ‘@’ followed by a valid username, then send the message only to that user.



## Concepts
The concepts behind this application are dependent on the multithreaded server. Before understanding the whole big term, let's understand what thread and server are?
##### Thread
Before diving deeper in thread let understand what a process is?
The process is a program that is executed in a CPU. So, Thread is a lightweight process or simply it's the smallest unit of a program that is executed by CPU. Threads in programming language help in reducing execution time by creating multiple threads and running them parallelly.
Once All threads(functionalities) executed, all these will be joined together to be a single thread. Similarly, here we will create new threads whenever a new client joined a server.
##### Server
A server is a software or hardware device that accepts and responds to requests made over a network. The device that makes the request, and receives a response from the server, is called a client. On the Internet, the term "server" commonly refers to the computer system which receives a request for a web document and sends the requested information to the client.

Combining both the terms we will create...

A server that can handle multiple threads, where each thread is responsible to process a separate request from every client(user). The server starts running a new thread whenever it finds a coming request meant for itself. Also, the server should provide facilities, so that concurrent threads can run safely without disrupting each other's operations.


## Tech-Stack
- [C++]

## Resources

 - https://www.youtube.com/watch?v=TPVH_coGAQs&list=PLk6CEY9XxSIAeK-EAh3hB4fgNvYkYmghp&index=1
 - geeksforgeeks.org/socket-programming-in-java/
