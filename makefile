OBJS = actor.o enemy.o player.o map.o map_schemas.o extraCredit.o
CC = g++
DEBUG = -g
CFLAGS = -c
CSTD = -std=c++11

extra: $(OBJS)
	$(CC) $(DEBUG) -o extra $(OBJS) $(CSTD)

actor.o: characters/actor.cpp characters/actor.h
	$(CC) $(DEBUG) $(CFLAGS) characters/actor.cpp $(CSTD)
enemy.o: characters/enemy.cpp characters/enemy.h
	$(CC) $(DEBUG) $(CFLAGS) characters/enemy.cpp $(CSTD)
player.o: characters/player.cpp characters/player.h
	$(CC) $(DEBUG) $(CFLAGS) characters/player.cpp $(CSTD)
map.o: state/map.cpp state/map.h
	$(CC) $(DEBUG) $(CFLAGS) state/map.cpp $(CSTD)
map_schemas.o: state/map_schemas.cpp state/map_schemas.h
	$(CC) $(DEBUG) $(CFLAGS) state/map_schemas.cpp $(CSTD)
extraCredit.o: extraCredit.cpp
	$(CC) $(DEBUG) $(CFLAGS) extraCredit.cpp $(CSTD)
