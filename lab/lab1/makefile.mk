a.out: Client.o Server.o
	gcc Client.o Server.o -o a.out 
Server.o: Server.c
	gcc -c Server.c
Client.o: Client.c
	gcc -c Client.c
