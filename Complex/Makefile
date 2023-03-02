G = g++
FLAGS = -Wall -Wextra -Werror

all : complex 

libcomplex.a : complex.o
	ar rc libcomplex.a complex.o
complex : libcomplex.a complex_test.o
	$(G) $(FLAGS) -o ../build/complex complex_test.o -L. -lcomplex
complex.o : complex.cpp
	$(G) $(FLAGS) complex.cpp -c -o complex.o
complex_test.o : complex_test.cpp
	$(G) $(FLAGS) complex_test.cpp -c -o complex_test.o
clean : 
	rm -rf *.o *.out *.a ../build/*
rebuild : clean all