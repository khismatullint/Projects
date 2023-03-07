G = g++
FLAGS = -Wall -Wextra -Werror

all : forwardlist 

libforwardlist.a : forwardlist.o
	ar rc libforwardlist.a forwardlist.o
	ranlib libforwardlist.a
forwardlist : libforwardlist.a test.o
	$(G) $(FLAGS) -o ../build/forwardlist test.o -L. -lforwardlist
forwardlist.o : forwardlist.cpp
	$(G) $(FLAGS) forwardlist.cpp -c -o forwardlist.o
test.o : test.cpp
	$(G) $(FLAGS) test.cpp -c -o test.o
clean : 
	rm -rf *.o *.out *.a ../build/*
rebuild : clean all