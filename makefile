all:
	g++ -no-pie main.cpp global.cpp global.h arena.cpp characters.cpp characters.h fight.cpp save.cpp load.cpp -o CMDArena
