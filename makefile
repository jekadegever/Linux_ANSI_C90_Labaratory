magic : magic.o magicSquare_Test.o magicSquare_io.o
	gcc -g -Wall -ansi -pedantic magic.o magicSquare_Test.o magicSquare_io.o -o magic

magic.o : magic.c magicSquare.h
	gcc -c -Wall -ansi -pedantic magic.c -o magic.o

magicSquare_Test.o : magicSquare_Test.c magicSquare.h
	gcc -c -Wall -ansi -pedantic magicSquare_Test.c -o magicSquare_Test.o

magicSquare_io.o : magicSquare_io.c magicSquare.h
	gcc -c -Wall -ansi -pedantic magicSquare_io.c -o magicSquare_io.o

