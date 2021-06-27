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
	echo -e "\e[1mIf you see 'It Works!', then the test was successful!\e[0m"
	./temp echo "It works"
