CC ?= gcc
PREFIX ?= /usr/local

all: temp

temp: dollarskip.c
	$(CC) dollarskip.c -o temp

install: temp
	install -m 755 temp $(PREFIX)/bin/\$

uninstall:
	-rm $(PREFIX)/bin/\$

clean:
	-rm temp

build-debug: dollarskip.c
	$(CC) dollarskip.c -o temp -g -Wall
