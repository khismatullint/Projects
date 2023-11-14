CC =gcc
CFLAGS =-Wall -Werror -Wextra -std=c11
GCOV_FLAGS =-fprofile-arcs -ftest-coverage
FLAGS_CHECK = $(shell pkg-config --cflags --libs check)
all: s21_decimal.a test gcov_report

s21_decimal.a: 
	$(CC) $(CFLAGS) -c s21_decimal.c 
	ar rc s21_decimal.a s21_decimal.o
	ranlib s21_decimal.a
	@-rm -rf *.o
test:
	$(CC) $(CFLAGS) -c test.c
	$(CC)  *.o s21_decimal.a -o test $(FLAGS_CHECK)
	./test
gcov_report:
	gcc $(GCOV_FLAGS) *.c -o report.out $(FLAGS_CHECK)
	./report.out
	lcov -t "report" -o report.info -c -d .
	genhtml -o ./report report.info
	#open -a "Safari" report/index.html
clean:
	@-rm *.gcda *.gcno *.info *.out *.o *.a test
	@rm -rf report
rebuild: clean s21_decimal.a test gcov_report
style:
	cp ../materials/linters/.clang-format .
	clang-format -i *.c
	clang-format -i *.h
	rm .clang-format
valgrind:
	 @valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s --trace-children=yes --track-fds=yes --log-file=valgrind.log ./test || true
	 @grep -F "ERROR SUMMARY" valgrind.log