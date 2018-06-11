CC=gcc
CFLAGS=-W -Wall -ansi -pedantic -g
LDFLAGS=`sdl-config --cflags --libs` -lm -lSDL_ttf -g 
EXEC=sprite
SRC=sprite.c graphlib.c sprite.c
OBJ=$(SRC:.c=.o)

all: $(EXEC)

sprite: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)


%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS)

.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
			
