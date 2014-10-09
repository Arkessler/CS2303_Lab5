# Makefile for RoboMall program

OBJS = lab5.o small.o init_mall.o decide.o tile.o

CC = g++
CFLAGS = -Wall -c
LFLAGS = -Wall

lab5 : $(OBJS)
	$(CC) $(LFLAGS) -lm $(OBJS) -o lab5

lab5.o: globals.h lab5.cpp
	$(CC) $(CFLAGS) lab5.cpp

init_mall.o : externals.h globals.h init_mall.cpp
	$(CC) $(CFLAGS) init_mall.cpp

decide.o : externals.h globals.h decide.cpp
	$(CC) $(CFLAGS) decide.cpp
	
tile.o: tile.h tile.cpp
	$(CC) $(CFLAGS) tile.cpp
	
small.o : externals.h small.cpp
	$(CC) $(CFLAGS) small.cpp
clean:
	\rm *.o 

