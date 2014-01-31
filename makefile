CC=g++
all:
	$(CC) $(CFLAGS) -c Data.cpp -J obj/ -o obj/Data.o
	$(CC) $(CFLAGS) -c calcmd.cpp -I obj/ -o obj/calcmd.o
	$(CC) $(CFLAGS) -c main.cpp -I obj/ -o obj/main.o
	$(CC) $(CFLAGS)  -o bin/l.exe ./obj/Data.o obj/calcmd.o main.o
clean:
	rm -f obj/*.*
