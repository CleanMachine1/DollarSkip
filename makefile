.SILENT: test

make: dollarskip.c
	gcc dollarskip.c -o temp
install: make
	cp temp /usr/bin/\$
uninstall: install
	rm /usr/bin/\$
clean: make
	rm temp
build-debug: dollarskip.c
	gcc dollarskip.c -o temp -g -Wall
