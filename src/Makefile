CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11

all: clean s21_math.a test gcov_report

s21_math.a:
	$(CC) $(CFLAGS) *.c -c
	ar rc s21_math.a *.o
	ranlib s21_math.a

test: clean s21_math.a
	@$(CC) $(CFLAGS) --coverage tests/*.c s21_math.a -o test -lcheck -lm -lsubunit -lpthread
	@./test

gcov_report:
	lcov -t "s21_math_test" -o fizzbuzz.info -c -d .
	genhtml -o report fizzbuzz.info
	open -a "Google Chrome" report/src/index.html

clean:
	@-rm -rf *.o && rm -rf *.gcno
	@-rm -rf *.a && rm -rf *.gcda
	@-rm -rf *.info && rm -rf *.gcov
	@-rm -rf ./test && rm -rf ./gcov_report
	@-rm -rf ./report/
	@-rm -rf s21_test main

style: clean
	cp ../materials/linters/.clang-format .
	clang-format --style=file -i *.c *.h tests/*.c tests/*.h
	rm .clang-format