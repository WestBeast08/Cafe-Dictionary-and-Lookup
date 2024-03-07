dict1: main.o dictionary.o data.o processing.o
	gcc -g -o dict1 main.o dictionary.o data.o processing.o

main.o: main.c
	gcc -g -c main.c

dictionary.o: dictionary.c
	gcc -g -c dictionary.c

data.o: data.c
	gcc -g -c data.c

processing.o: processing.c
	gcc -g -c processing.c


clean:
	-rm dict1 *.o

