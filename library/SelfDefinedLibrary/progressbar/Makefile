
CFLAGS = -std=c99 -I. -Wall -g

all: clean test
	@:

test: $(SRC)
	$(CC) $^ progress.c test.c $(CFLAGS) -o test-progress
	./test-progress

clean:
	rm -rf test-progress


.PHONY: clean test
