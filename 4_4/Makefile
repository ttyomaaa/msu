a.exe: main.o f.o func.o
	gcc -Wall main.o f.o func.o -o a.exe
main.o: main.c f.h func.h
	gcc -Wall -c main.c -o main.o
f.o: f.c f.h func.h
	gcc -Wall -c f.c -o f.o
func.o: func.c func.h
	gcc -Wall -c func.c -o func.o
clean:
	rm -f *.o
	rm -f *.exe
	rm -f b.txt 