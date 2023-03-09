G = g++
FLAGS = -Wall -Wextra -Werror

all : stack 

libstack.a : stack.o
	ar rc libstack.a stack.o
	ranlib libstack.a
stack : libstack.a test.o
	$(G) $(FLAGS) -o ../build/stack test.o -L. -lstack
stack.o : stack.cpp
	$(G) $(FLAGS) stack.cpp -c -o stack.o
test.o : test.cpp
	$(G) $(FLAGS) test.cpp -c -o test.o
clean : 
	rm -rf *.o *.out *.a ../build/*
rebuild : clean all