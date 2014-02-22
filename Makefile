CC=g++
CFLAG=-lm
program=socket 
all: $(program)
socket: socket.o
	$(CC) $(CFLAG) -o $@ socket.o
socket_release: socket_release.o
	$(CC) $(CFLAG) -o $@ socket_release.o -O3
socket_debug: socket_debug.o
	$(CC) $(CFLAG) -o $@ socket_debug.o -g
socket_prof: socket_prof.o
	$(CC) $(CFLAG) -o $@ socket_prof.o -pg
socket.o: socket.cpp
	$(CC) $(CFLAG) -c -o $@ socket.cpp
socket_release.o: socket.cpp
	$(CC) $(CFLAG) -c -o $@ socket.cpp -O3
socket_debug.o: socket.cpp
	$(CC) $(CFLAG) -c -o $@ socket.cpp -g
socket_prof.o: socket.cpp
	$(CC) $(CFLAG) -c -o $@ socket.cpp -pg
clean:
	rm -fr *.o socket socket_release socket_debug socket_prof
