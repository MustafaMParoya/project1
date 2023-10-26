 main: main.c project1.o
	gcc project1.o main.c -o main.out -Wall -Werror


project1: project1.c
	gcc project1.c -c -Wall -Werror

clean:
	rm -rf *.o main.out	