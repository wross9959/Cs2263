GCC = gcc
CFLAGS = -g -Wall -Wshadow

htags: a2/htags.o 
	$(GCC) $(CFLAGS) htags.o -o htags

htags2: a3/htags2.o
	$(GCC) $(CFLAGS) htags2.o -o htags2

a2/htags.o: a2/htags.c
	$(GCC) $(CFLAGS) -c a2/htags.c

a3/htags2.o: a3/htags2.c
	$(GCC) $(CFLAGS) -c a3/htags2.c


testall: test0 test1

test0: htags
	./htags < inputs/input.html > outputs/output0.txt
	diff expected/expected0.txt outputs/output0.txt

test1: htags2
	./htags2 inputs/input.html > outputs/output1.txt
	diff expected/expected1.txt outputs/output1.txt

clean:
	/bin/rm -f *.o prog outputs/*
