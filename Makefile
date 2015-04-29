all: neatbrowse

CFLAGS=-std=c99 -g -I/usr/include -L/lib -L/usr/lib -Wall

filesystem.o: filesystem.c
	gcc $(CFLAGS) -c filesystem.c

main.o: main.c
	gcc $(CFLAGS) -c main.c

terminal.o: terminal.c
	gcc $(FLAGS) -c terminal.c

clean:
	rm main.o filesystem.o terminal.o neatbrowse

neatbrowse: main.o filesystem.o terminal.o
	gcc $(CFLAGS) main.o filesystem.o terminal.o -o neatbrowse
