CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
OBJECTS = chip8.o main.o test.o
DEPENDS = $(OBJECTS:.o=.d)
EXEC = test

$(EXEC): $(OBJECTS)
	$(CXX) $(OBJECTS) -g -o $(EXEC)

-include $(DEPENDS)

.PHONY: clean

clean:
	rm -f $(OBJECTS) $(DEPENDS) $(EXEC)