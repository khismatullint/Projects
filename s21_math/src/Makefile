CFLAGS=-Wall -Wextra -Werror -std=c11
CC=gcc
SOURCE_FILES=$(wildcard source/*.c)
OBJECT_FILES=$(patsubst %.c,%.o,$(notdir $(SOURCE_FILES)))
LDFLAGS=
GCOVFLAGS=--coverage -fprofile-arcs -ftest-coverage

LIBNAME=s21_math.a

all: $(LIBNAME) test

gcov_report: export LDFLAGS := $(LDFLAGS) -lgcov
gcov_report: build_coverage build_tests run_tests
	lcov -o tests.info -c -d .  
	genhtml -o report tests.info

build_coverage: export CFLAGS := $(CFLAGS) $(GCOVFLAGS)
build_coverage: clean $(LIBNAME)

$(LIBNAME):
	$(CC) $(CFLAGS) -I. -c $(SOURCE_FILES)
	ar rcs $(LIBNAME) $(OBJECT_FILES)
	rm -rf *.o

test: $(LIBNAME) build_tests run_tests

build_tests: LDFLAGS+=$(shell pkg-config --libs check)
build_tests:
	$(CC) test/s21_test_abs.c $(LIBNAME) $(LDFLAGS) -I. -o s21_test_abs
	$(CC) test/s21_test_acos.c $(LIBNAME) $(LDFLAGS) -I. -o s21_test_acos
	$(CC) test/s21_test_asin.c $(LIBNAME) $(LDFLAGS) -I. -o s21_test_asin
	$(CC) test/s21_test_atan.c $(LIBNAME) $(LDFLAGS) -I. -o s21_test_atan
	$(CC) test/s21_test_ceil.c $(LIBNAME) $(LDFLAGS) -I. -o s21_test_ceil
	$(CC) test/s21_test_cos.c $(LIBNAME) $(LDFLAGS) -I. -o s21_test_cos
	$(CC) test/s21_test_exp.c $(LIBNAME) $(LDFLAGS) -I. -o s21_test_exp
	$(CC) test/s21_test_fabs.c $(LIBNAME) $(LDFLAGS) -I. -o s21_test_fabs
	$(CC) test/s21_test_floor.c $(LIBNAME) $(LDFLAGS) -I. -o s21_test_floor
	$(CC) test/s21_test_fmod.c $(LIBNAME) $(LDFLAGS) -I. -o s21_test_fmod
	$(CC) test/s21_test_log.c $(LIBNAME) $(LDFLAGS) -I. -o s21_test_log
	$(CC) test/s21_test_pow.c $(LIBNAME) $(LDFLAGS) -I. -o s21_test_pow
	$(CC) test/s21_test_sin.c $(LIBNAME) $(LDFLAGS) -I. -o s21_test_sin
	$(CC) test/s21_test_sqrt.c $(LIBNAME) $(LDFLAGS) -I. -o s21_test_sqrt
	$(CC) test/s21_test_tan.c $(LIBNAME) $(LDFLAGS) -I. -o s21_test_tan

run_tests:
	./s21_test_acos
	./s21_test_asin
	./s21_test_cos
	./s21_test_log
	./s21_test_exp
	./s21_test_abs
	./s21_test_pow
	./s21_test_ceil
	./s21_test_atan
	./s21_test_fabs
	./s21_test_floor
	./s21_test_fmod
	./s21_test_sin
	./s21_test_sqrt
	./s21_test_tan

clean:
	rm -rf *.o *.gc* $(LIBNAME) s21_test* *.info report

lint:
	clang-format --style=Google **/*.c **/*.h -n

lint-fix:
	clang-format --style=Google -i **/*.c **/*.h

rebuild: clean all