CC := gcc
CFLAGS := -g -Wall -pthread
OBJS := common.o thr_pool.o history.o

all: server client

server: $(OBJS) server.o
	$(CC) $(CFLAGS) -o $@ $^

client: $(OBJS) client.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c *.h
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) -rf *.o *~
