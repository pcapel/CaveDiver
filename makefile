OBJS = enemy.o player.o extraCredit.o
CC = g++
DEBUG = -g
CFLAGS = -c
CSTD = -std=c++11

extra: enemy.o player.o extraCredit.o
	$(CC) $(DEBUG) -o extra enemy.o player.o extraCredit.o $(CSTD)

enemy.o: characters/enemy.cpp characters/enemy.h
	$(CC) $(DEBUG) $(CFLAGS) character/enemy.cpp $(CSTD)
player.o: characters/player.cpp characters/player.h
	$(CC) $(DEBUG) $(CFLAGS) character/player.cpp $(CSTD)
extraCredit.o: extraCredit.cpp
	$(CC) $(DEBUG) $(CFLAGS) extraCredit.cpp $(CSTD)
