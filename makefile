PROG = RunGame
CC = g++
OBJS = Graph.o Printing.o main.o
CPPFLAGS = -Wall -std=c++11

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)
Graph.o : Graph.h
	$(CC) $(CPPFLAGS) -c Graph.cpp
Printing.o : Printing.h
	$(CC) $(CPPFLAGS) -c Printing.cpp
main.o :
	$(CC) $(CPPFLAGS) -c main.cpp
clean:
	$(RM) $(PROG) $(OBJS)
