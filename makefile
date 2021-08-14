CC?=gcc

all: temp

temp: dollarskip.c
	$(CC) dollarskip.c -o temp

install: temp
	cp temp /usr/bin/\$

zshinstall: temp
	cp temp /usr/bin/\%

uninstall:
	-rm /usr/bin/\$

clean:
	-rm temp

build-debug: dollarskip.c
	$(CC) dollarskip.c -o temp -g -Wall
