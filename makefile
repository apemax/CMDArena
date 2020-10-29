CC = g++
CXXFLAGS = -no-pie -Werror -Wall -Wextra
DEPS = global.h enemy.h player.h store.h attack.h defend.h

ODIR = obj
BUILD_DIR = build

BIN = CMDArena

_OBJ = main.o global.o arena.o player.o enemy.o store.o attack.o defend.o fight.o save.o load.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

.SECONDEXPANSION:

$(ODIR)/%.o: %.cpp $(DEPS) | $$(@D)
	$(CC) -c -o $@ $< $(CXXFLAGS)

$(BUILD_DIR)/CMDArena: $(OBJ) | $$(@D)
	$(CC) -o $@ $^ $(CXXFLAGS)

$(BUILD_DIR):
	mkdir -p $@
	cp commands enemy-presets build

$(ODIR):
	mkdir -p $@

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(BUILD_DIR)/$(BIN)
