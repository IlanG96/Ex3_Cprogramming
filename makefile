FLAGS=-Wall -g
CC=gcc


all: stringProg


stringProg:main.o Functions.a
		$(CC) $(FLAGS) -o stringProg main.o Functions.a


main.o:main.c Functions.h
		$(CC)   $(FLAGS) -c main.c


Functions.o: Functions.c Functions.h
		$(CC)   $(FLAGS) -c Functions.c


Functions.a: Functions.o 
			ar -rcs Functions.a Functions.o
			ranlib Functions.a


.PHONY: clean all

clean: 
	rm -f *o *a stringProg