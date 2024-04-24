# Open the 2023111023 folder in terminal
# Enter the following commands
#    1. mkdir temp
#    2. make
#    3. ./my_program
# The execution should start now, and user can start interacting with the C program.
# 
# Enter quit to terminate the C program.
# After finishing, user can run make clean to get rid of the .o files


CC = gcc
SRC_DIR = code
INC_DIR = code
OBJ_DIR = temp

SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SOURCES))
EXECUTABLE = my_program

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXECUTABLE)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -rf $(EXECUTABLE) $(OBJ_DIR)

