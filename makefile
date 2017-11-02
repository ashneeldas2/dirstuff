all: dirstuff.c
	gcc -o dirstuff dirstuff.c
run: dirstuff
	./dirstuff
	
