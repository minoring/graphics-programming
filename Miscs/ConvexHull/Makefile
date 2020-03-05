CC=g++ 
CFLAGS=-std=c++11
LDFLAGS=-lglfw -lGLEW -framework OpenGL
HEADERS=/usr/local/include
SOURCES=src/Application.cpp
OBJS=
TARGET=app

all: $(TARGET)

graham: GrahamScan.cpp shader.o
	$(CC) GrahamScan.cpp Shader.o $(CFLAGS) -o $@ $(LDFLAGS)

shader.o: Shader.h
	$(CC) -c Shader.cpp $(CFLAGS) -o $@ $(LDFLAGS)

clean:
	rm -f *.o
	rm -f $(TARGET)
