all:
	g++ -no-pie main.cpp global.cpp global.h arena.cpp player.cpp player.h enemy.cpp enemy.h fight.cpp save.cpp load.cpp -o CMDArena
