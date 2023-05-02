CC=g++
CFLAGS=-Wall -Wextra -pedantic -Wimplicit-fallthrough=0 -std=c++20 -c -O3
LDFLAGS=
SOURCES=$(wildcard src/*.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=guppy

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)