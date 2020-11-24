CC=gcc
AR=ar
FLAGS= -Wall -g
FILES= myBank.c
OBJECT_LIB= myBank.o
STATIC_LIB= libmyBank.a
LDLIBS = -lm

.PHONY: all clean

export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH

all: main

main:  libmyBank.a main.o
	$(CC) $(FLAGS) -o main main.o libmyBank.a $(LDLIBS)

#libmyBank.a: myBank.o
#	$(AR) -rcs libmyBank.a myBank.o

libmyBank.a: $(OBJECT_LIB)
	ar -rcs libmyBank.a $(OBJECT_LIB)

myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c -o myBank.o myBank.c

main.o: main.c myBank.h
	$(CC) $(FLAGS) -c -o main.o main.c




clean:
	rm -f *.o *.a *.so main