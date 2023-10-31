wordcount: wordcount.o bst.o data.o
	gcc -o wordcount wordcount.o bst.o data.o

wordcount.o: wordcount.c bst.h
	gcc -c wordcount.c

bst.o: bst.c bst.h
	gcc -c bst.c
data.o: data.c data.h
    gcc -c data.c