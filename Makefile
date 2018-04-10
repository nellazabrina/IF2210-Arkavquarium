# Masukkan semua file cpp Anda
OBJS = Lib/oop.cpp Aquarium.cpp Coin.cpp Fish.cpp Food.cpp Guppy.cpp main.cpp Moveable.cpp Pet.cpp Piranha.cpp Siput.cpp

CC = g++
COMPILER_FLAGS = -std=c++11 -Wall -O2
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf
OBJ_NAME = oopquarium
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
