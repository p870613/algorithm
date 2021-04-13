CXX=g++
CFLAGS= -Wall

all: node.o head.o
	$(CXX) -o main $(CFLAGS) $^ linked_list.cpp
%.c : %.o
	$(CXX) -c $(CFLAGS) $^
clean:
	rm -rf *.o
	rm -rf main
