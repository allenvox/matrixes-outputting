CPPFLAGS = -Wall -Wextra
all: main
.PHONY: main
main: main.cpp
	g++ $(CPPFLAGS) -o $@ $^
clean:
	rm -rf main