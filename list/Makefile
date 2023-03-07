G = g++
FLAGS = -Wall -Wextra -Werror

all : list 

liblist.a : list.o
	ar rc liblist.a list.o
	ranlib liblist.a
list : liblist.a test.o
	$(G) $(FLAGS) -o ../build/list test.o -L. -llist
list.o : list.cpp
	$(G) $(FLAGS) list.cpp -c -o list.o
test.o : test.cpp
	$(G) $(FLAGS) test.cpp -c -o test.o
clean : 
	rm -rf *.o *.out *.a ../build/*
rebuild : clean all