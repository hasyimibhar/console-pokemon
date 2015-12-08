CC = g++
CFLAGS = -Wall
TARGET = pokemon

$(TARGET):
	$(CC) $(CFLAGS) -o $(TARGET) main.cpp Move.cpp Monster.cpp Moves.cpp Monsters.cpp Battle.cpp Game.cpp

clean:
	rm $(TARGET)
