CFLAGS=-O3 -W -Wall -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -fstack-protector-all -Wfloat-equal -Wpointer-arith -Wwrite-strings -Wno-long-long -Wmissing-declarations -Wdeclaration-after-statement --all-warnings -lm 

a.out: main.o f.o li.o
	gcc main.o f.o li.o -o a.out
main.o: main.c f.c f.h li.h li.c
	gcc -c $(CFLAGS) main.c f.c li.c
f.o: f.c f.h
	gcc -c $(CFLAGS) f.c
li.o: li.c li.h
	gcc -c $(CFLAGS) li.c

clean:
	rm -f main.o f.o li.o
	rm -f a.out