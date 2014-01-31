CC=g++
CFLAGS=-Wall -std=c++0x
all:
	$(CC) $(CFLAGS) -c Data.cpp -J obj/ -o obj/Data.o
	$(CC) $(CFLAGS) -c calcmd.cpp -I obj/ -o obj/calcmd.o
	$(CC) $(CFLAGS) -c main.cpp -I obj/ -o obj/main.o
	$(CC) $(CFLAGS)  -o bin/program.exe obj/Data.o obj/calcmd.o obj/main.o
clean:
	rm -f obj/*.* bin/*.*
