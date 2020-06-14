CFLAGS=--all-warnings
a.exe: main.o f.o
	gcc main.o f.o -o a.exe
main.o: main.c f.h
	gcc -c $(CFLAGS) main.c
f.o: f.c f.h
	gcc -c $(CFLAGS) f.c

a2.exe: main2.o f2.o
	gcc main2.o f2.o -o a2.exe
main2.o: main2.c f.h
	gcc -c $(CFLAGS) main2.c
f2.o: f.c f.h
	gcc -c $(CFLAGS) f2.c

clean:
	rm -f *.o
	rm -f *.exe
	rm -f b.txt 