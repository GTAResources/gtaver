CPP=g++
CC=gcc
CFLAGS=-O3 -g -Wall
SRC=main.cpp 
OBJ=$(SRC:.cpp=.o)
BIN=ver.exe

all: $(SRC) $(BIN)

clean:
	rm -rf $(OBJ) $(BIN)
	
$(BIN): $(OBJ) 
	$(CC) $(CFLAGS) $(OBJ) -o $@