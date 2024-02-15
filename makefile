CC := gcc
CFLAGS := -Wall -Wextra -Wconversion -O2
SOURCE := main.c
OBJECT := main.o

output: $(OBJECT)
	$(CC) $(CFLAGS) $(OBJECT) -o output

$(OBJECT): $(SOURCE)
	$(CC) $(SOURCE) -c

clean:
	rm $(OBJECT) output
