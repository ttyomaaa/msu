CFLAGS =-fstack-protector-all -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -std=gnu99 -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Wold-style-definition -Wdeclaration-after-statement -Wbad-function-cast -Wnested-externs

all: a01.out a02.out a03.out a04.out a05.out a06.out a07.out
a01.out: main1.o matrix.o f1.o 
	gcc main1.o matrix.o f1.o -o a01.out
main1.o: main1.c matrix.h f1.h
	gcc -c $(CFLAGS) main1.c
matrix.o: matrix.c matrix.h
	gcc -c $(CFLAGS) matrix.c
f1.o: f1.c f1.h matrix.h
	gcc -c $(CFLAGS) f1.c

a02.out: main2.o matrix.o f2.o
	gcc main2.o matrix.o f2.o -o a02.out
main2.o: main2.c matrix.h f2.h
	gcc -c $(CFLAGS) main2.c
f2.o: f2.c f2.h matrix.h
	gcc -c $(CFLAGS) f2.c

a03.out: main3.o matrix.o f3.o
	gcc main3.o matrix.o f3.o -o a03.out
main3.o: main3.c matrix.h f3.h
	gcc -c $(CFLAGS) main3.c
f3.o: f3.c f3.h matrix.h
	gcc -c $(CFLAGS) f3.c
	
a04.out: main4.o matrix.o f4.o
	gcc main4.o matrix.o f4.o -o a04.out
main4.o: main4.c matrix.h f4.h
	gcc -c $(CFLAGS) main4.c
f4.o: f4.c f4.h matrix.h
	gcc -c $(CFLAGS) f4.c

a05.out: main5.o matrix.o f5.o
	gcc main5.o matrix.o f5.o -o a05.out
main5.o: main5.c matrix.h f5.h
	gcc -c $(CFLAGS) main5.c
f5.o: f5.c f5.h matrix.h
	gcc -c $(CFLAGS) f5.c

a06.out: main6.o matrix.o f6.o
	gcc main6.o matrix.o f6.o -o a06.out
main6.o: main6.c matrix.h f6.h
	gcc -c $(CFLAGS) main6.c
f6.o: f6.c f6.h matrix.h
	gcc -c $(CFLAGS) f6.c

a07.out: main7.o matrix.o f7.o
	gcc main7.o matrix.o f7.o -o a07.out
main7.o: main7.c matrix.h f7.h
	gcc -c $(CFLAGS) main7.c
f7.o: f7.c f7.h matrix.h
	gcc -c $(CFLAGS) f7.c

clean:
	rm -f f1.o f2.o f3.o f4.o f5.o f6.o f7.o f8.o f9.o f10.o f11.o main1.o main2.o main3.o main4.o main5.o main6.o main7.o main8.o main9.o main10.o matrix.o
	rm -f a01.out a02.out a03.out a04.out a05.out a06.out a07.out a08.out a09.out a10.out
