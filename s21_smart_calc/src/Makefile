CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 
TESTFLAGS = --coverage

SRCS = $(wildcard s21*.c)
TESTS = $(wildcard tests/*.c)
OBJS = $(SRCS:.c=.o)
TEST_OBJS = $(TESTS:.c=.o)
LIBS = -lcheck -lm -lpthread

all: run

install:
	@-cd S21_calc && qmake 
	@-cd S21_calc && make

uninstall:
	@-rm -rf ./S21_calc/S21_calc.app/
	@-cd ./S21_calc && make clean
dvi: install
	@-open Instruction.html
	
dist: clean
	@-tar cvf S21_smart_calc.tar $(SRCS) $(TESTS) s21_calculator.h ./S21_calc/* Makefile

run: install
	-@ ./S21_calc/S21_calc.app/Contents/MacOS/S21_calc


test:$(OBJS) $(TEST_OBJS)
	$(CC) $(CFLAGS) $(LIBS) -o $@ $^
	./test

clean: 
	@-rm -f $(OBJS) $(TEST_OBJS)
	@-rm -rf tests/*.info tests/*.gcno tests/*.gcda
	@-rm test test.info S21_smart_calc.tar
	@-rm -rf report
	@-rm -rf build-S21_calc-Desktop_x86_darwin_generic_mach_o_64bit-Debug
	@cd ./S21_calc && make clean

gcov_report: clean add_coverage test
	mkdir report
	lcov -t "test" -o test.info -c -d . 
	genhtml -o report test.info
	open report/index.html
	rm -rf *.gcda *.gcno *.out

add_coverage:
	$(eval CFLAGS += --coverage)

style:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -i *.c
	clang-format -i *.h
	clang-format -n *.c
	rm .clang-format

