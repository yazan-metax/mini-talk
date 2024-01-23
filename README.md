<h1 align="center"> MINITALK PROGRAM 🎙️</h1>

# description:

### The Mini Talk project, implemented in C, demonstrates the creation of a simple communication system. It serves as a practical example of network programming and inter-process communication (IPC) in C, as part of the 42 School curriculum.

# Features🔥:

- **Server-Client Architecture:** Basic client-server model using socket programming in C.
- **Real-time Communication:** Facilitates real-time messaging between clients via the server.
- **Concurrent Connections:** Manages multiple client connections using C-specific methods.

# Technologies and Concepts ⚙️:

- **Language:** C
- **Compiler/Tools:** GCC, Makefile, Git,file(.h), file(.c)
- **Libraries:** Standard C libraries(`<signal.h>`), minitalk.h
- **Unix Signals:** Employs SIGUSR1 and SIGUSR2 for communication between client and server.
- **Bitwise Operations:** Manages message encoding and decoding at the bit level.
- **Signal Handling:**  Implements custom signal handlers for inter-process communication.

# Key Functions and Concepts🔑:

## Client-Side:

**`arg_config`:** Validates command line arguments, ensuring correct PID and non-empty message.

**`send_func`:** Encodes the message into bits and sends it to the server using Unix signals (SIGUSR1 and SIGUSR2).

**`sig_func and sig_config`:** Configures signal handling to acknowledge message reception.

**`Inter-process Communication`:** Utilizes Unix signals for sending messages bit by bit.

## serve-side:

**`handler_func`:** Receives bits of the message, reconstructs the character, and prints it. Acknowledges reception back to the client.

**`sig_config`:** Sets up signal handling for SIGUSR1 and SIGUSR2 to receive message bits.

**`Signal-driven Communication:`** Uses signals to receive message bits and control the flow of data.


# Getting Started👍🏻

## Installation⬇

```
git clone https://github.com/yazan-metax/mini-talk.git
cd mini-talk
make
```
# Usage 🚀

```
./server
./client [server PID] [message]

```
# How It Works

## Server Setup
- this server does not use traditional socket programming. Instead, it uses Unix signal handling to receive and reconstruct messages sent from the client. The server continuously runs in a loop, waiting for signals (`SIGUSR1` and `SIGUSR2`).

## Client Communication

- The client sends messages to the server using Unix signals. Each character of the message is encoded into bits and sent sequentially. The client uses the `kill` function to send signals representing the bits of each character.

## Concurrency Handling

- This implementation does not explicitly handle concurrency. The server handles one message at a time as it's based on Unix signal handling. For concurrency, one might consider using threads or handling multiple signal queues.

# Skills Acquired

## Network Programming in C

- nstead of traditional network programming, this project explores inter-process communication using Unix signals, a fundamental concept in system-level programming in C.

## IPC in C

- Gained practical experience in using Unix signals for IPC, demonstrating how processes can communicate and synchronize their actions without shared memory.

## Memory Management

- The project involves careful management of variables and efficient use of resources, critical in C programming.

## Debugging and Testing

- Debugging skills are enhanced by working through the challenges of signal handling and process synchronization in C.


# License 🚩

This project is made available under the terms of this license:

Permission is granted to anyone to use, modify, and distribute this software in any form, for any purpose, including commercial applications. The author provides this software "as-is" without warranty of any kind, either expressed or implied, including but not limited to the implied warranties of merchantability and fitness for a particular purpose. In no event shall the author be held liable for any damages arising from the use of the software.
