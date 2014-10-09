# Makefile for RoboMall program

OBJS = robomall.o small.o init_mall.o decide.o tile.o

CC = g++
CFLAGS = -Wall -c
LFLAGS = -Wall

Robosim : $(OBJS)
	$(CC) $(LFLAGS) -lm $(OBJS) -o Robosim

robomall.o : globals.h robomall.cpp
	$(CC) $(CFLAGS) robomall.cpp

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

