.PHONY: all clean uninstall install

CC ?= gcc
STRIP ?= strip
PREFIX ?= /usr/local
CFLAGS += -g -Wall -Wextra -Wpedantic

all: dollarskip

install: dollarskip
	$(STRIP) dollarskip
	install -d $(DESTDIR)$(PREFIX)/bin
	install -m 755 dollarskip $(DESTDIR)$(PREFIX)/bin/\$

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/\$

clean:
	rm -f dollarskip
