CC				= gcc
WARNING			= -Wall -Wextra -Werror
C11				= -std=c11 -pedantic
SOURCE_FILES	= create_matrix.c remove_matrix.c eq_matrix.c utility.c sum_matrix.c sub_matrix.c mult_number.c mult_matrix.c transpose.c calc_complements.c determinant.c inverse_matrix.c
OBJ_FILES		= create_matrix.o remove_matrix.o eq_matrix.o utility.o sum_matrix.o sub_matrix.o mult_number.o mult_matrix.o transpose.o calc_complements.o determinant.o inverse_matrix.o
TEST_FILES		= tests/create_remove_test.c tests/eq_test.c tests/sum_test.c tests/sub_test.c tests/mult_number_test.c tests/mult_matrix_test.c tests/transpose_test.c  tests/determinant_test.c tests/calc_complements_test.c tests/inverse_test.c
TEST_OBJ		= create_remove_test.o eq_test.o sum_test.o sub_test.o mult_number_test.o mult_matrix_test.o transpose_test.o  determinant_test.o calc_complements_test.o inverse_test.o
GCOVF 			= -fprofile-arcs -ftest-coverage


.PHONY: matrix.a test

all: matrix.a

matrix.a:
	$(CC) $(WARNING) $(C11) -c $(SOURCE_FILES)
	ar rc matrix.a $(OBJ_FILES)
	ranlib matrix.a

test: clean matrix.a
	$(CC) -c -o tests/main.o test.c
	$(CC) -c $(TEST_FILES)
	$(CC) -lcheck $(TEST_OBJ) tests/main.o matrix.a -o test
	./test

clean:
	rm -rf *.gcda *.gcov *.o *.gcno tests/*.o tests/*.gcno *.info test matrix.a res

lint:
	clang-format -n *.c *.h -style=Google

fix_lint:
	clang-format -i *.c *.h -style=Google

mem_leaks:
	leaks -atExit -- ./test

coverage: clean $(SOURCE_FILES)
	$(CC) --coverage -c -g $(SOURCE_FILES)
	ar rc matrix.a $(OBJ_FILES)
	ranlib matrix.a
	$(CC) -c -o tests/main.o test.c
	$(CC) -c $(TEST_FILES)
	$(CC) -lcheck $(TEST_OBJ) --coverage tests/main.o matrix.a -o test
	- ./test
	lcov -f -c --directory . -o ./coverage.info
	genhtml coverage.info --output-directory=res
	open res/index.html