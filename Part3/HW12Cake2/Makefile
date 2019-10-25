#***
# DO NOT modify this file 
# ***
# 	
#
WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose


TESTFALGS = -DTEST_ELIMINATE -DDEBUG -DTEST_DELETENODE -DTEST_CREATELIST 


SRCS = main.c hw12.c
OBJS = $(SRCS:%.c=%.o)


main: $(OBJS) 
	$(GCC) $(TESTFALGS) $(OBJS) -o main


.c.o: 
	$(GCC) $(TESTFALGS) -c $*.c


testmemory: main
	$(VAL) ./main 6 4 > output2																							
testall: test1 test2 test3


test1: main
	./main 6 3 > output1
	diff output1 expected/expected1


test2: main
	./main 6 4 > output2
	diff output2 expected/expected2 																																
test3: main
	./main 25 7 > output3
	diff output3 expected/expected3 																																											
clean: # remove all machine generated files
	rm -f main *.o output?



