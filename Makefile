CPPFLAGS = -Wall -Wextra

all: main

.PHONY: main
main: operations.o matrix.o print.o main.o
	g++ $(CPPFLAGS) -o $@ $^

%.o: %.c
	g++ $(CPPFLAGS) -c -o $@ $<

clean:
	rm -rf main *.o