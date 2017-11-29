CC=g++
CC_FLAGS=-Wall --std=c++11
EXEC=Feature_Selection.out
SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)

$(EXEC): $(OBJECTS)
	$(CC) -g  $(OBJECTS) -o  $(EXEC)

%.o: %.cpp
	$(CC) -c -g $(CC_FLAGS) $< -o $@

clean:
	rm -f $(EXEC) $(OBJECTS)
