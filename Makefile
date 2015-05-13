all: neatbrowse

CFLAGS=-std=c99 -g -I/usr/include -L/lib -L/usr/lib -Wall

filesystem.o: filesystem.c
	$(CC) $(CFLAGS) -c filesystem.c

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

terminal.o: terminal.c
	$(CC) $(FLAGS) -c terminal.c

clean:
	rm main.o filesystem.o terminal.o neatbrowse

neatbrowse: main.o filesystem.o terminal.o
	$(CC) $(CFLAGS) main.o filesystem.o terminal.o -o neatbrowse
