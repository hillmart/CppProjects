CC=g++ -g
EXE_FILE=pokemon

all: $(EXE_FILE)

$(EXE_FILE): pokemon.o pokemon.h prog.cpp
	$(CC) pokemon.o prog.cpp -o $(EXE_FILE)

pokemon.o: pokemon.h pokemon.cpp
	$(CC) -c pokemon.cpp

clean:
	rm -f *.o $(EXE_FILE)