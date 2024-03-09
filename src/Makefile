CC=gcc
CFLAGS=-Wall -Wextra -Werror -Wpedantic -std=c11
OFLAGS=-o
GCOV=--coverage
OS=$(shell uname -s)

ifeq ($(OS), Linux)
	OPEN_CMD=xdg-open
	ADD_LIB=-pthread -lcheck_pic -pthread -lrt -lm -lsubunit
	LEAK_CHECK=valgrind --tool=memcheck --leak-check=yes
else ifeq ($(OS), Darwin)
	OPEN_CMD=open
	ADD_LIB=-lm -lcheck -lpthread
	LEAK_CHECK=leaks -atExit --
endif

all: s21_string.a test gcov_report clean

s21_string.a: clean
	@$(CC) -c $(CFLAGS) s21_*.c
	ar -rcs s21_string.a s21_*.o
	@rm -rf *.o

test: clean
	@$(CC) -c $(CFLAGS) *.c unit_tests/*.c $(ADD_LIB)
	@$(CC) $(CFLAGS) -o test *.o $(ADD_LIB)
	./test
	@rm -rf *.o test

gcov_report:
	@$(CC) -c $(CFLAGS) $(GCOV) *.c unit_tests/*.c $(ADD_LIB)
	@$(CC) $(CFLAGS) $(GCOV) -o gcov_test *.o $(ADD_LIB)
	./gcov_test
	@lcov -c -d . -o gcov_test.info
	@rm -rf *.out *.o *.gcno *.gcda gcov_test
	@genhtml -o report gcov_test.info
	@chmod 777 report/*
	@$(OPEN_CMD) ./report/index.html
	@rm -rf report/ *.info

leaks: clean
	@$(CC) -c $(CFLAGS) *.c unit_tests/*.c $(ADD_LIB)
	@$(CC) $(CFLAGS) -o leaks_test *.o $(ADD_LIB)
	$(LEAK_CHECK) ./leaks_test
	@rm -rf leaks_test

clean:
	@rm -rf *.out *.o *.a
	@rm -rf *.gcno *.gcda *.info
	@rm -rf report/
	@rm -rf test gcov_test leaks_test

clang:
	@clang-format -i *.c *.h unit_tests/*.h unit_tests/*.c
