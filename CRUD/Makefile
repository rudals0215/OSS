a.out: main.o extras.o base.o
	gcc -o a.out main.o extras.o base.o

main.o: main.c base.h extras.h record.h
	gcc -c -o main.o main.c

extras.o: extras.c extras.h
	gcc -c -o extras.o extras.c

base.o: base.c base.h
	gcc -c -o base.o base.c

clean:
	rm -rf *.o a.out
