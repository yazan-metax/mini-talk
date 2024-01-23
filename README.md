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
- **Libraries:** Standard C libraries, minitalk.h
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

