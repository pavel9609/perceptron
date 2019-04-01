CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp perceptron.o
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=rgz.exe

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@