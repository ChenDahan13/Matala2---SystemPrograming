CC = gcc
FLAGS = -Wall -g 
MYMAT = my_mat.o my_mat.h

main: main.o libmy_mat.a
	$(CC) $(FLAGS) main.o -o main libmy_mat.a

libmy_mat.a: $(MYMAT)
	ar rc libmy_mat.a $(MYMAT)

main.o: main.c my_mat.h
	$(CC) $(FLAGS) -c main.c -o main.o

my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c my_mat.c 

all: my_mat.o main.o libmy_mat.a main

clean:
	rm *.o *.a main