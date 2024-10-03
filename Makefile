CC = gcc

CFLAGS  = -g -Wall

TARGET = lscav

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c
	konsole --hold -e ~/Documents/Projects/LSCAV/$(TARGET)

clean:
	$(RM) $(TARGET)
