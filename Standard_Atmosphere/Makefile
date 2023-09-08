CC = g++
CFLAGS = -Wall -std=c++11
EXECUTABLE = atm

SOURCES = main.cc Table/Table.cc Analytical/Analytical.cc

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE)
