# TFTP-Client
an  extended  TFTP  (Trivial  File  Transfer  Protocol) 
client.
 The  communication  is performed  using  a  binary  communication  protocol,  which  will  support  the  upload, 
download and lookup of files
## Introduction 
   The client runs 2 threads. One is reading from keyboard while the other is reading from socket. Both threads may write 
   to the socket.
   The client should recive commands using the standard input
    ## Supported Commands
  The extended TFTP supports 10 types of packets:
  ```
  1     Read request (RRQ)
  2     Write request (WRQ)
  3     Data (DATA)
  4     Acknowledgment (ACK)
  5     Error (ERROR)
  6     Directory listing request (DIRQ)
  7     Login request (LOGRQ)
  8     Delete request (DELRQ)
  9     Broadcast file added/deleted (BCAST)
  10    Disconnect (DISC)
  ```
  ## Testing run commands
  Client:
  ```
  TFTPclient <ip> <port>
  ```
