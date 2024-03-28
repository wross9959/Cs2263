GCC = gcc
CFLAGS = -g -Wall -Wshadow

prog: aredistinct.o main.o
	$(GCC) $(CFLAGS) aredistinct.o main.o -o prog # no -c

aredistinct.o: aredistinct.c
	$(GCC) $(CFLAGS) -c aredistinct.c

main.o: main.c
	$(GCC) $(CFLAGS) -c main.c

testall: test0 test1 test2

test0: prog
	./prog inputs/input0.txt > outputs/output0.txt
	diff expected/expected0.txt outputs/output0.txt

test1: prog
	./prog inputs/input1.txt > outputs/output1.txt
	diff expected/expected1.txt outputs/output1.txt

test2: prog
	./prog inputs/input2.txt > outputs/output2.txt
	diff expected/expected2.txt outputs/output2.txt

clean:
	/bin/rm -f *.o prog outputs/*
