all: neatbrowse

CFLAGS=-I/usr/include -L/lib -L/usr/lib -lncurses -Wall

main.o:
	gcc $(CFLAGS) -c main.c

clean:
	rm main.o neatbrowse

neatbrowse: main.o
	gcc $(CFLAGS) main.o -o neatbrowse
