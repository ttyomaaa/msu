CFLAGS=-O3 -W -Wall -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -fstack-protector-all -Wfloat-equal -Wpointer-arith -Wwrite-strings -Wno-long-long -Wmissing-declarations -Wdeclaration-after-statement --all-warnings -lm 

a.out: main.o f.o
	gcc main.o f.o -o a.out
main.o: main.c f.h
	gcc -c $(CFLAGS) main.c
f.o: f.c f.h
	gcc -c $(CFLAGS) f.c
	
clean:
	rm -f main.o f.o
	rm -f a.out