CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = sales_report

all: $(TARGET)

$(TARGET): sales_report.c
		$(CC) $(CFLAGS) -o $(TARGET) sales_report.c

clean:
		rm -f $(TARGET)