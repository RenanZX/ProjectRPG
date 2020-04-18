# raylib compiled with
# make OS=Windows_NT CC=x86_64-w64-mingw32-gcc

APPNAME=rpgGame

#COMPILER_PATH=C:/raylib/mingw/bin/

LDFLAGS:=-L../raylib/src -lm -lraylib -static -static-libgcc -static-libstdc++ -pthread -lopengl32 -lgdi32 -lwinmm -mwindows -Werror

CFLAGS:= -g -Wfatal-errors -pedantic -Wall -Wextra
CFLAGS+= -std=c++11 -I ./include -I ../raylib/src

SRC:=$(wildcard src/*.cpp)
OBJ:=$(SRC:src/%.cpp=obj/%.o)
INC:=$(wildcard lib/*.hpp)

CC=x86_64-w64-mingw32-g++
#CC=g++

all: $(APPNAME).exe clear

$(APPNAME).exe: $(OBJ)
	$(CC) $(OBJ) -o $(APPNAME).exe $(LDFLAGS)

$(OBJ): obj/%.o : src/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: debug release
debug: CFLAGS+= -g
release: CFLAGS+= -O3

debug release: clean $(APPNAME)

.PHONY:	clean
clean:
	rm -f obj/*
	rm -f $(APPNAME).exe

style: $(SRC) $(INC)
	astyle -A10 -s4 -S -p -xg -j -z2 -n src/* include/*

clear:
	rm -rf ./obj/*.o
