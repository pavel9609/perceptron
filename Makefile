CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp perceptron.o
OBJECTS=$(SOURCES:.cpp=.o)
ifeq ($(OS),Windows_NT)
	EXECUTABLE=rgz.exe
else
	EXECUTABLE=rgz
endif

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@