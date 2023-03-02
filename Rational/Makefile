G = g++
FLAGS = -Wall -Wextra -Werror

all : rational

rational : rational.cpp rational_test.cpp
	$(G) $(FLAGS) rational.cpp rational_test.cpp -o ../build/rational
clean : 
	rm -rf *.o *.out ../build/*
rebuild : clean all
