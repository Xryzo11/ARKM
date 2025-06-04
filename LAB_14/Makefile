all: main

main.o: main.c
	gcc -c main.c

asmfunc.o: asmfunc.s
	gcc -c asmfunc.s

main: main.o asmfunc.o
	gcc -no-pie -o main main.o asmfunc.o

clean:
	rm -f main main.o asmfunc.o