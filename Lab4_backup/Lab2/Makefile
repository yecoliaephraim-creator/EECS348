CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = lab2
OBJS = main.o isEven.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c isEven.h
	$(CC) $(CFLAGS) -c main.c

isEven.o: isEven.c isEven.h
	$(CC) $(CFLAGS) -c isEven.c

clean:
	rm -f $(TARGET) $(OBJS)
