CC = gcc
CFLAGS = -Wall -Wextra -g -I.
TARGET = programa.exe

# Localiza os arquivos
SRCS = main.c $(wildcard backend_p/*.c) $(wildcard frontend_p/*.c)
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /f /q $(OBJS) $(TARGET)

run: all
	./$(TARGET)