CC = g++
CXXFLAGS = -no-pie -Wall
DEPS = global.h enemy.h player.h store.h weapons.h

ODIR = obj

BIN = CMDArena

_OBJ = main.o global.o arena.o player.o enemy.o store.o weapons.o fight.o save.o load.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CXXFLAGS)

CMDArena: $(OBJ)
	$(CC) -o $@ $^ $(CXXFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(BIN)
