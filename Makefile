CFLAGS =-fstack-protector-all -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -std=gnu99 -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Wold-style-definition -Wdeclaration-after-statement -Wbad-function-cast -Wnested-externs

all: a.out
a.out: main17.o matrix.o f17.o 
	gcc main17.o matrix.o f17.o -o a.out
main17.o: main17.c matrix.h f17.h
	gcc -c $(CFLAGS) main17.c
matrix.o: matrix.c matrix.h
	gcc -c $(CFLAGS) matrix.c
f17.o: f17.c f17.h matrix.h
	gcc -c $(CFLAGS) f17.c

clean:
	rm -f f17.o main17.o matrix.o
	rm -f a.out
