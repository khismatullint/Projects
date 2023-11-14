FLAGS=-Wall -Werror -Wextra -std=c11

UNAME := $(shell uname -s)
ifeq ($(UNAME), Linux)
	FLAGS +=  -lsubunit
endif

all: clean s21_string.a
deafult: all
s21_string.o: functions/*.c sprintf/*.c sscanf/*.c C_sharp/*.c
	gcc $(FLAGS) -c $^ -I functions -I sprintf
s21_string.a: s21_string.o
	ar cr s21_string.a *.o
clean:
	rm -rf *.a *.o *.out *.html *.css *.gcno *.gcov *.gcda s21_test report
format:
	clang-format -i *.c *.h 
test: clean
	gcc $(FLAGS) $(COVERAGE) -o s21_test  s21_test.c tests/*.c functions/*.c sprintf/*.c sscanf/*.c C_sharp/*.c -I functions -I sprintf -I sscanf -I C_sharp -lcheck -lm -lsubunit
	./s21_test 

add_coverage:
	$(eval FLAGS += --coverage)
gcov_report: add_coverage test
	./s21_test
	gcov -b -l -p -c s21_*.gcno
	gcovr -o gcov_report.html --html --html-details -g -k -r . --html --html-details --filter functions/ --filter sscanf/ --filter sprintf/ --filter C_sharp/
	open gcov_report.html
