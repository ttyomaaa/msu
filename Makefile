CFLAGS = -W -Wall -Wextra -pedantic -Wmissing-prototypes -Wstrict-prototypes -Wold-style-definition -Werror -Wfloat-equal -std=c99 -Wunused -Wcast-align -Werror -pedantic-errors -fstack-protector-all -Wpointer-arith -Wwrite-strings -Wcast-align -Wno-long-long -Wmissing-declarations

all: a01.exe a02.exe a03.exe a04.exe a05.exe a06.exe a07.exe a08.exe a09.exe a10.exe

a01.exe: main1.o matrix.o f1.o
	gcc main1.o matrix.o f1.o -o a01.exe
main1.o: main1.c matrix.h f1.h
	gcc -c $(CFLAGS) main1.c
matrix.o: matrix.c matrix.h
	gcc -c $(CFLAGS) matrix.c
f1.o: f1.c f1.h
	gcc -c $(CFLAGS) f1.c

a02.exe: main2.o matrix.o f2.o
	gcc main2.o matrix.o f2.o -o a02.exe
main2.o: main2.c matrix.h f2.h
	gcc -c $(CFLAGS) main2.c
f2.o: f2.c f2.h
	gcc -c $(CFLAGS) f2.c

a03.exe: main3.o matrix.o f3.o
	gcc main3.o matrix.o f3.o -o a03.exe
main3.o: main3.c matrix.h f3.h
	gcc -c $(CFLAGS) main3.c
f3.o: f3.c f3.h
	gcc -c $(CFLAGS) f3.c
	
a04.exe: main4.o matrix.o f4.o
	gcc main4.o matrix.o f4.o -o a04.exe
main4.o: main4.c matrix.h f4.h
	gcc -c $(CFLAGS) main4.c
f4.o: f4.c f4.h
	gcc -c $(CFLAGS) f4.c

a05.exe: main5.o matrix.o f5.o
	gcc main5.o matrix.o f5.o -o a05.exe
main5.o: main5.c matrix.h f5.h
	gcc -c $(CFLAGS) main5.c
f5.o: f5.c f5.h
	gcc -c $(CFLAGS) f5.c

a06.exe: main6.o matrix.o f6.o
	gcc main6.o matrix.o f6.o -o a06.exe
main6.o: main6.c matrix.h f6.h
	gcc -c $(CFLAGS) main6.c
f6.o: f6.c f6.h
	gcc -c $(CFLAGS) f6.c

a07.exe: main7.o matrix.o f7.o
	gcc main7.o matrix.o f7.o -o a07.exe
main7.o: main7.c matrix.h f7.h
	gcc -c $(CFLAGS) main7.c
f7.o: f7.c f7.h
	gcc -c $(CFLAGS) f7.c

a08.exe: main8.o matrix.o f8.o
	gcc main8.o matrix.o f8.o -o a08.exe
main8.o: main8.c matrix.h f8.h
	gcc -c $(CFLAGS) main8.c
f8.o: f8.c f8.h
	gcc -c $(CFLAGS) f8.c
	
a09.exe: main9.o matrix.o f9.o
	gcc main9.o matrix.o f9.o -o a09.exe
main9.o: main9.c matrix.h f9.h
	gcc -c $(CFLAGS) main9.c
f9.o: f9.c f9.h
	gcc -c $(CFLAGS) f9.c

a10.exe: main10.o matrix.o f10.o
	gcc main10.o matrix.o f10.o -o a10.exe
main10.o: main10.c matrix.h f10.h
	gcc -c $(CFLAGS) main10.c
f10.o: f10.c f10.h
	gcc -c $(CFLAGS) f10.c

clean:
	rm -f f1.o f2.o f3.o f4.o f5.o f6.o f7.o f8.o f9.o f10.o main1.o main2.o main3.o main4.o main5.o main6.o main7.o main8.o main9.o main10.o matrix.o
	rm -f a01.out a02.out a03.out a04.out a05.out a06.out a07.out a08.out a09.out a10.out
