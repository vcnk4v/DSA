# Directories
DIRS = 1 2 3 4

# Source files
SRC = main.c heap.c hash.c

# Object files
OBJ = $(foreach dir,$(DIRS),$(addprefix $(dir)/,$(SRC:.c=.o)))

# Executable files
EXE = $(foreach dir,$(DIRS),$(dir)/q$(dir).o)

# Default target
all: $(EXE)

# Rule to build object files
%.o: %.c
	gcc -c $< -o $@

# Rules to build executables
1/q1.o: 1/main.o 1/hash.o
	gcc -o $@ $^

2/q2.o: 2/main.o 2/hash.o
	gcc -o $@ $^

3/q3.o: 3/main.o 3/heap.o
	gcc -o $@ $^

4/q4.o: 4/main.o 4/heap.o
	gcc -o $@ $^

# Phony targets
.PHONY: clean

# Clean target
clean:
	rm -f $(OBJ) $(EXE)