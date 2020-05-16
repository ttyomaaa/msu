CFLAGS =-fstack-protector-all -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -std=gnu99 -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Wold-style-definition -Wdeclaration-after-statement -Wbad-function-cast -Wnested-externs

all: a01.out a02.out a03.out a04.out a05.out a06.out a08.out a09.out a10.out a11.out a12.out
a01.out: main1.o fx.o f13.o 
	gcc -lm main1.o fx.o f13.o -lm -o a01.out
main1.o: main1.c fx.h
	gcc -c $(CFLAGS) main1.c
fx.o: fx.c fx.h
	gcc -c $(CFLAGS) -lm fx.c
f13.o: f13.c fx.h
	gcc -c $(CFLAGS) -lm f13.c

a02.out: main2.o fx.o f13.o 
	gcc -lm main2.o fx.o f13.o -lm -o a02.out
main2.o: main2.c fx.h
	gcc -c $(CFLAGS) main2.c

a03.out: main3.o fx.o f13.o 
	gcc -lm main3.o fx.o f13.o -lm -o a03.out
main3.o: main3.c fx.h
	gcc -c $(CFLAGS) main3.c
	
a04.out: main4.o fx.o f47.o 
	gcc -lm main4.o fx.o f47.o -lm -o a04.out
main4.o: main4.c fx.h
	gcc -c $(CFLAGS) main4.c
f47.o: f47.c fx.h
	gcc -c $(CFLAGS) -lm f47.c
	
a05.out: main5.o fx.o f47.o 
	gcc -lm main5.o fx.o f47.o -lm -o a05.out
main5.o: main5.c fx.h
	gcc -c $(CFLAGS) main5.c
	
a06.out: main6.o fx.o f47.o 
	gcc -lm main6.o fx.o f47.o -lm -o a06.out
main6.o: main6.c fx.h
	gcc -c $(CFLAGS) main6.c
	
a08.out: main8.o fx.o f89.o 
	gcc -lm main8.o fx.o f89.o -lm -o a08.out
main8.o: main8.c fx.h
	gcc -c $(CFLAGS) main8.c
f89.o: f89.c fx.h
	gcc -c $(CFLAGS) -lm f89.c
	
a09.out: main9.o fx.o f89.o 
	gcc -lm main9.o fx.o f89.o -lm -o a09.out
main9.o: main9.c fx.h
	gcc -c $(CFLAGS) main9.c

a10.out: main10.o fx.o f1011.o 
	gcc -lm main10.o fx.o f1011.o -lm -o a10.out
main10.o: main10.c fx.h
	gcc -c $(CFLAGS) main10.c
f1011.o: f1011.c fx.h
	gcc -c $(CFLAGS) -lm f1011.c

a11.out: main11.o fx.o f1011.o 
	gcc -lm main11.o fx.o f1011.o -lm -o a11.out
main11.o: main11.c fx.h
	gcc -c $(CFLAGS) main11.c

a12.out: main12.o fx.o f12.o 
	gcc -lm main12.o fx.o f12.o -lm -o a12.out
main12.o: main12.c fx.h
	gcc -c $(CFLAGS) main12.c
f12.o: f12.c fx.h
	gcc -c $(CFLAGS) -lm f12.c

clean:
	rm -f f13.o f47.o f89.o f1011.o f12.o main1.o main2.o main3.o main4.o main5.o main6.o main7.o main8.o main9.o main10.o main11.o main12.o fx.o
	rm -f a01.out a02.out a03.out a04.out a05.out a06.out a07.out a08.out a09.out a10.out a11.out a12.out