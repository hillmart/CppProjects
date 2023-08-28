CC=g++ -g
EXE_FILE=wumpus

all: $(EXE_FILE)

$(EXE_FILE): driver.cpp room.o event.o pit.o gold.o wumpus.o bats.o empty.o
	$(CC) driver.cpp room.o event.o pit.o gold.o wumpus.o bats.o empty.o -o $(EXE_FILE)

room.o: room.cpp room.h
	$(CC) -c room.cpp
event.o: event.cpp event.h
	$(CC) -c event.cpp
pit.o: pit.cpp pit.h
	$(CC) -c pit.cpp
wumpus.o: wumpus.cpp wumpus.h
	$(CC) -c wumpus.cpp
gold.o: gold.cpp gold.h
	$(CC) -c gold.cpp
bats.o: bats.cpp bats.h
	$(CC) -c bats.cpp	
empty.o: empty.cpp empty.h
	$(CC) -c empty.cpp	

clean:
	rm -f *.o $(EXE_FILE)