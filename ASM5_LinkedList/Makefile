CC=g++ -g
EXE_FILE=test
EXE_FILE1=pattern

all: $(EXE_FILE) $(EXE_FILE1)

$(EXE_FILE): test_linked_list.cpp
	$(CC) test_linked_list.cpp -o $(EXE_FILE)

$(EXE_FILE1): pattern.cpp
	$(CC) pattern.cpp -o $(EXE_FILE1)

clean:
	rm -f *.o $(EXE_FILE)