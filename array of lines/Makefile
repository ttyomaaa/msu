CFLAGS=-O3 -W -Wall -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -fstack-protector-all -Wfloat-equal -Wpointer-arith -Wwrite-strings -Wno-long-long -Wmissing-declarations -Wdeclaration-after-statement --all-warnings -lm 

a.out: main.o f.o matrix.o
	gcc main.o f.o matrix.o -o a.out
main.o: main.c f.c f.h matrix.h matrix.c
	gcc -c $(CFLAGS) main.c f.c matrix.c
f.o: f.c f.h
	gcc -c $(CFLAGS) f.c
matrix.o: matrix.c matrix.h
	gcc -c $(CFLAGS) matrix.c

clean:
	rm -f main.o f.o matrix.o
	rm -f a.out