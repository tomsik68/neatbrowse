all: neatbrowse

CFLAGS=-std=c99 -I/usr/include -L/lib -L/usr/lib -lncurses -Wall

filesystem.o: filesystem.c filesystem.h
	gcc $(CFLAGS) -c filesystem.c

main.o: main.c filesystem.o
	gcc $(CFLAGS) -c main.c

clean:
	rm main.o neatbrowse

neatbrowse: main.o
	gcc $(CFLAGS) main.o filesystem.o -o neatbrowse
