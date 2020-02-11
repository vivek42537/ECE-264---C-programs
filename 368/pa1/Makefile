WARNING = -Wall -Wshadow -pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g -O3 $(WARNING) $(ERROR)

SRCS =  pa1.c shell_list.c shell_array.c

OBJS = $(SRCS:%.c=%.o)

VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose

main: $(OBJS)
	$(GCC) $(OBJS) -o pa1
.c.o:
	$(GCC) -c $*.c
#gdb: gdb pa1 -a examples/15.b output2
testmemory: pa1
	$(VAL) ./pa1 -a examples/15.b output1

testall: test1 test2 test3 test4 test5 test6

test1: 
	./pa1 -a examples/15.b output1
	diff output1 examples/15sa.b

test2: 
	./pa1 -l examples/15.b output2
	diff output2 examples/15sl.b

test3:
	./pa1 -a examples/1K.b output3
	diff output3 examples/1Ksa.b

test4: $(TARGET)
	./$(TARGET) -l Inputs/1K.b 1000UL.b
	diff 1000UL.b Inputs/1Ksl.b

test5:
	./pa1 -a examples/10K.b output5
	diff output5 examples/10K.b

test6: $(TARGET)
	./$(TARGET) -l Inputs/10000.b 10000UL.b
	diff 10000UL.b 10000UA.b


test7:
	./pa1 -a examples/100K.b output7
	diff output7 examples/100Ksa.b

test8: $(TARGET)
	./$(TARGET) -l Inputs/100000.b 100000UL.b
	diff 100000UL.b 100000UA.b


test9:
	./pa1 -a examples/1M.b output9
	diff output9 examples/1Msa.b

test10: $(TARGET)
	./$(TARGET) -l Inputs/1000000.b 1000000UL.b
	diff 1000000UL.b 1000000UA.b

test11: 
	./pa1 -a empty.b emptyUA.b

test12: $(TARGET)
	./$(TARGET) -l empty.b emptyUL.b
	diff emptyUA.b emptyUL.b

clean:
	rm -f split $(OBJS) $(TARGET) *.output
