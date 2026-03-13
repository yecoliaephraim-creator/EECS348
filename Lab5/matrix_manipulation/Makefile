CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = matrix

all: $(TARGET)

$(TARGET): matrix.c
	$(CC) $(CFLAGS) -o $(TARGET) matrix.c

clean:
	rm -f $(TARGET)