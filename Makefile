CFLAGS=-std=c11 -g -static
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)

largest: $(OBJS)
	$(CC) -o largest $(OBJS) $(LDFLAGS)

$(OBJS): largest.h
