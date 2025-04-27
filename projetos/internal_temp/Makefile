CC = gcc
CFLAGS = -I ./mocks -I ~/libs/Unity/src -I .
SRC = temperature_test.c ~/libs/Unity/src/unity.c internal_temp.c
TARGET = temperature_test

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
