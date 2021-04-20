CXX=g++
CFLAGS= -Wall
build=build
all: node.o head.o
	$(CXX) -o main $(CFLAGS) $^ circular_linked_list.cpp
%.c : %.o
	$(CXX) -c $(CFLAGS) -o $(build)/$@
clean:
	rm -rf *.o
	rm -rf main
