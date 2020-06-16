1) Updated with file handling and dynamic allocation of packet size(done by taking another buffer and sending that after allocating P bytes to it), as previously had turned in code without it.
2) FIle is run in the form ./a.out <ip> <T> <P> <filename>
3) Data is written of the form <packetno,T,P,time in microsec>
4) Graph is also attached, of 5 datagarams, the python program for graph plotting hangs for more than 6-7 points.
5) Graph explanation - time taken by initial packets is the most (maybe related to time taken for socket creation as well) and the rest of the packets have lesser and similar times.
 
