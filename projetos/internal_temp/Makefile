CC = gcc
CFLAGS = -I ./mocks -I ~/libs/Unity/src -I . # Ajuste o caminho para o Unity
SRC = temperature_test.c ~/libs/Unity/src/unity.c internal_temp.c # Ajuste o caminho para o Unity
TARGET = temperature_test

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
