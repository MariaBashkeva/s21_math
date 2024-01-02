CC = gcc -std=c11
CFLAGS = -Wall -Wextra -Werror -std=c11


OS := $(shell uname -s)
ifeq ($(OS), Darwin)
 TEST_FLAGS = -lcheck -lm -lpthread
else
 TEST_FLAGS = -lcheck -lm -lpthread -lrt -lsubunit
endif


all: s21_math.a


s21_math.a:
	$(CC) -c $(CFLAGS) s21_exp.c -o s21_exp.o
	$(CC) -c $(CFLAGS) s21_acos.c -o s21_acos.o
	$(CC) -c $(CFLAGS) s21_asin.c -o s21_asin.o
	$(CC) -c $(CFLAGS) s21_sqrt.c -o s21_sqrt.o
	$(CC) -c $(CFLAGS) s21_fabs.c -o s21_fabs.o
	$(CC) -c $(CFLAGS) s21_ceil.c -o s21_ceil.o
	$(CC) -c $(CFLAGS) s21_floor.c -o s21_floor.o
	$(CC) -c $(CFLAGS) s21_log.c -o s21_log.o
	$(CC) -c $(CFLAGS) s21_abs.c -o s21_abs.o
	$(CC) -c $(CFLAGS) s21_fmod.c -o s21_fmod.o
	$(CC) -c $(CFLAGS) s21_pow.c -o s21_pow.o
	$(CC) -c $(CFLAGS) s21_sin.c -o s21_sin.o
	$(CC) -c $(CFLAGS) s21_cos.c -o s21_cos.o
	$(CC) -c $(CFLAGS) s21_tan.c -o s21_tan.o
	$(CC) -c $(CFLAGS) s21_atan.c -o s21_atan.o
	$(CC) -c $(CFLAGS) s21_powint.c -o s21_powint.o
	$(CC) -c $(CFLAGS) s21_factoriall.c -o s21_factoriall.o
	ar rc s21_math.a s21_acos.o s21_asin.o s21_exp.o s21_sqrt.o s21_fabs.o s21_ceil.o s21_floor.o s21_log.o s21_abs.o s21_fmod.o s21_pow.o s21_sin.o s21_cos.o s21_tan.o s21_powint.o s21_factoriall.o s21_atan.o
	ranlib s21_math.a
style:
	clang-format -style=Google -n *.c *.h

test: s21_math.a
	 gcc -Wextra -Werror -Wall -g s21_math_test.c s21_math.a -o test $(TEST_FLAGS)
	 ./test

gcov_report: s21_math.a
	$(CC) $(CFLAGS)  $(TEST_FLAGS) *.c --coverage  -o test
	./test
	gcov *.c
	lcov -t "proverka" -o result.info -c -d .
	genhtml -o report result.info
	open report/index.html
lcov:
	brew install lcov

brew:
	cd
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh

clean:
	rm -f s21_math
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info
	rm -rf test
	rm -rf report
	rm -rf *.o
	rm -rf *.a
	rm -rf *.gcov

rebuild: clean s21_math.a
