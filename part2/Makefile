CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lm
TARGET = poisson
SRC = Poisson.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(TARGET)
