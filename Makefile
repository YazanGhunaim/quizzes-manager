CFLAGS = -Wall -pedantic -O2 -Wextra -fsanitize=address -g -std=c++17 -I/usr/include/libxml2/
LFLAGS = -fsanitize=address -lxml2
SRC = $(wildcard src/*.cpp) # find all .cpp files in the src directory.

OBJS = $(SRC:src/%.cpp=obj/%.o) 
# replace the src/ prefix of each file in SRC with obj/ and the .cpp extension with .o. 
# This will create a corresponding object file in the obj directory for each source file in the src directory.
DEPS = dependencies.make
EXEC = prog

all: $(EXEC)

# creates the obj directory if it doesn't exist, and uses the src/%.cpp pattern to find the corresponding source file for each object file.
obj/%.o: src/%.cpp $(DEPS)
	mkdir -p obj
	g++ $(CFLAGS) -c $< -o $@

$(EXEC): $(OBJS)
	g++ $(LFLAGS) $^ -o $@

clean:
	rm -rf obj $(EXEC) $(DEPS)

run: $(EXEC)
	./$(EXEC)

install:
	@echo "Downloading and installing libxml2..."
	sudo apt-get update && sudo apt-get install -y libxml2-dev

.PHONY: all clean run

$(DEPS): # create the obj directory if it doesn't exist.
	mkdir -p obj
	g++ -MM $(SRC) > $(DEPS)

-include $(DEPS) # include the $(DEPS) file in the Makefile.