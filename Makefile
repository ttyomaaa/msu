CFLAGS = -O3 -fstack-protector-all -W -Werror -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -std=gnu99 -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Wold-style-definition -Wdeclaration-after-statement -Wbad-function-cast -Wnested-externs

all: a.out
a.out: main.o f.o 
	gcc -lm main.o f.o -o a.out
main.o: main.c 
	gcc -c $(CFLAGS) main.c
f.o: f.c f.h
	gcc -c $(CFLAGS) f.c

clean:
	rm -f f.o main.o
	rm -f a.out
