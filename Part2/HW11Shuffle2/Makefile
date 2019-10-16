RRNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

TESTFALGS = -DTEST_MAIN -DTEST_DIVIDE -DTEST_INTERLEAVE -DTEST_SHUFFLE

SRCS = main.c shuffle.c
OBJS = $(SRCS:%.c=%.o)

hw11: $(OBJS)
	$(GCC) $(TESTFALGS) $(OBJS) -o hw11

.c.o:
	$(GCC) $(TESTFALGS) -c $*.c

testmemory: hw11
	$(VALGRIND) ./hw11 4 3 | sort | uniq > output1.txt
	$(VALGRIND) ./hw11 4 5 | sort | uniq > output2.txt
	$(VALGRIND) ./hw11 5 2 | sort | uniq > output3.txt
	$(VALGRIND) ./hw11 6 2 | sort | uniq > output4.txt
	$(VALGRIND) ./hw11 7 3 | sort | uniq > output5.txt
	$(VALGRIND) ./hw11 8 2 | sort | uniq > output6.txt
	$(VALGRIND) ./hw11 11 2 | sort | uniq > output7.txt

testall: test1 test2 test3 test4 test5 test6 test7

test1: hw11
	./hw11 4 3 | sort | uniq > output1.txt
	diff -i -w output1.txt expected/expected_4_3

test2: hw11
	./hw11 4 5 | sort | uniq > output2.txt
	diff -i -w output2.txt expected/expected_4_5

test3: hw11
	./hw11 5 2 | sort | uniq > output3.txt
	diff -i -w output3.txt expected/expected_5_2

test4: hw11
	./hw11 6 2 | sort | uniq > output4.txt
	diff -i -w output4.txt expected/expected_6_2

test5: hw11
	./hw11 7 3 | sort | uniq > output5.txt
	diff -i -w output5.txt expected/expected_7_3

test6: hw11
	./hw11 8 2 | sort | uniq > output6.txt
	diff -i -w output6.txt expected/expected_8_2

test7: hw11
	./hw11 11 2 | sort | uniq > output7.txt
	diff -i -w output7.txt expected/expected_11_2

clean:
	rm -f hw11 *.o output?

