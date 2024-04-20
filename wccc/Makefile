CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS =

SRCS = wc.c parser.c
OBJS = $(SRCS:.c=.o)
EXEC = wccc

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(EXEC) $(OBJS)
