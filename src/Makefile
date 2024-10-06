CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
GCOVFLAGS = -fprofile-arcs-ftest-coverage
SOURCES = s21_*.c
OBJECTS = $(SOURCES:.c=.o)
SOURCES_TEST = unit_tests.c
OS = $(shell uname -s)

ifeq ($(OS), Linux)
	OPEN = xdq-open
	CFLAGS += -D OS_LINUX
	CHECKFLAGS = -lpthread -lcheck -pthread -lrt -lm -lsubunit
endif

ifeq ($(OS), Darwin)
	OPEN = open
	CFLAGS += -D OS_MAC
	CHECKFLAGS = -lcheck
endif

all: clean s21_matrix.a test

s21_matrix.a: $(OBJECTS)
	$(CC) $(CFLAGS) -c $(SOURCES)
	@ar rcs s21_matrix.a $(OBJECTS)
	@rm -rf ./*.o

test: rebuild $(SOURCES_TEST)
	$(CC) $(CFLAGS) $(SOURCES_TEST) s21_matrix.a $(CHECKFLAGS) -o test
	./test

gcov_report: rebuild
	$(CC) $(CFLAGS) -o test *.c --coverage -L. s21_matrix.a $(CHECKFLAGS)
	./test
	gcov unit_tests.c
	lcov -t "test" -o result.info -c -d .
	genhtml -o ./report result.info

clang:
	@cp ../materials/linters/.clang-format .clang-format
	clang-format -i *.c *.h
	@rm .clang-format

valgrind: test
	valgrind --tool=memcheck --leak-check=yes ./test

leaks: test
	CK_FORK=no leaks -atExit -- ./test $t > testleaks.log
	open testleaks.log
	make clean

rebuild: clean s21_matrix.a

clean:
	@rm -rf ./a.out ./*.o ./*.gch ./*.a ./test ./GcovReport ./report ./*.info ./*.gcno ./*gcda ./*.gcov ./report gcov_report*