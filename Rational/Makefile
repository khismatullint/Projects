G = g++
FLAGS = -Wall -Wextra -Werror

all : rational 

librational.a : rational.o
	ar rc librational.a rational.o
	ranlib librational.a
rational : librational.a rational_test.o
	$(G) $(FLAGS) -o ../build/rational rational_test.o -L. -lrational
rational.o : rational.cpp
	$(G) $(FLAGS) rational.cpp -c -o rational.o
rational_test.o : rational_test.cpp
	$(G) $(FLAGS) rational_test.cpp -c -o rational_test.o
clean : 
	rm -rf *.o *.out *.a ../build/*
rebuild : clean all