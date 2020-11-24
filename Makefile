CC=gcc
AR=ar
FLAGS= -Wall -g
FILES= myBank.c
OBJECT_LIB= myBank.o
STATIC_LIB= libmyBank.a

.PHONY: all clean

export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH

all: main

main:  $(STATIC_LIB) main.o
	$(CC) $(FLAGS) -o main $^

libmyBank.a: myBank.o
	$(AR) -rcs libmyBank.a $(OBJECT_LIB)

myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c -o myBank.o myBank.c

main.o: main.c myBank.h
	$(CC) $(FLAGS) -c -o main.o main.c

clean:
	rm -f *.o *.a *.so main