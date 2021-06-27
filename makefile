.SILENT: test

make :
	gcc dollarskip.c -o temp
install :
	cp temp /usr/bin/\$
uninstall :
	rm /usr/bin/\$
clean :
	rm temp
build-debug :
	gcc dollarskip.c -o temp -Wall
test :
	./temp echo "It works"
