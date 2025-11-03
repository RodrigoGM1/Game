OBJS = main.o
CFLAGS = -g -Wall

all: game clean

game: $(OBJS)
	gcc -o $@ $?

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)