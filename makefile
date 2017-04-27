extra: enemy.o player.o extraCredit.o
	g++ -g -o extra enemy.o player.o extraCredit.o -std=c++11

enemy.o: enemy.cpp enemy.h
	g++ -g -c enemy.cpp -std=c++11
player.o: player.cpp player.h
	g++ -g -c player.cpp -std=c++11
extraCredit.o: extraCredit.cpp
	g++ -g -c extraCredit.cpp -std=c++11
