HEADERS = /usr/local/include
SOURCES = src/Application.cpp
CC = g++
CFLAGS = -std=c++11
LDFLAGS = -lglfw -lGLEW -framework OpenGL 
EXECUTABLE = ./a.out
RM = rm -rf

all: $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(SOURCES) $(LDFLAGS)

clean: 
	$(RM) *.o $(EXECUTABLE)