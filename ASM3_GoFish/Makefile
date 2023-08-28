CC=g++ -g
EXE_FILE=fish

all: $(EXE_FILE)

$(EXE_FILE): driver.cpp deck.o hand.o player.o game.o card.o
	$(CC) driver.cpp deck.o hand.o player.o game.o card.o -o $(EXE_FILE)

deck.o: deck.cpp deck.h
	$(CC) -c deck.cpp
hand.o: hand.cpp hand.h
	$(CC) -c hand.cpp
player.o: player.cpp player.h
	$(CC) -c player.cpp
game.o: game.cpp game.h
	$(CC) -c game.cpp
card.o: card.cpp card.h
	$(CC) -c card.cpp	

clean:
	rm -f *.o $(EXE_FILE)