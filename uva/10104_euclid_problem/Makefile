CXX=g++
EXE=main
FLAG=-o
FILENAME=main.cpp
TESTFILE=test.txt
all:
	$(CXX) $(FLAG) $(EXE) $(FILENAME)

run:
	$(CXX) $(FLAG) $(EXE) $(FILENAME)
	./$(EXE)

test:
	$(CXX) $(FLAG) $(EXE) $(FILENAME)
	./$(EXE) < $(TESTFILE)
clean:
	rm -f main

