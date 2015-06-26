

CC = gcc
CFLAGS = -Wall
LDFLAGS = 
EXEC = gameoflife

SRC= core.c  display.c  main.c   navigation.c  struct.c
OBJ= $(SRC:.c=.o)

all: $(EXEC)


$(EXEC): $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)

display.o: struct.h
struct.o: consts.h
core.o: struct.h consts.h
navigation.o: struct.h

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
			