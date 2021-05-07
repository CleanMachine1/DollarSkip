make :
	gcc dollarskip.c -o temp
install :
	cp temp /usr/bin/\$
uninstall :
	rm /usr/bin/\$
clean :
	rm temp