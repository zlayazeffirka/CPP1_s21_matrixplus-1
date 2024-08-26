CC = g++
CFLAGS = -Wall -Wextra -Werror -g -std=c++17
V_COMMAND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt
L_COMMAND = leaks -atExit
GCOVFLAGS = -fprofile-arcs -ftest-coverage

FILES=*.cpp
PATH_TO_TESTS = tests/
EXEC = s21_matrix_oop.a
EXEC_T = unit_tests
TEST_LIBS=-lcheck -lpthread -lsubunit -lm -lgcov
COV_REPORT=report/

SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))
SRC_T = $(wildcard $(PATH_TO_TESTS)*.cpp)
OBJ_T = $(patsubst %.cpp, %.o, $(SRC_T))

OS := $(shell uname -s)

# all: $(EXEC) tests gcov_report

all: clean gcov_report

s21_matrix_oop.a: $(OBJ)
	ar rc $@ $(OBJ)
	ranlib $@

test: $(OBJ_T) $(EXEC)

ifeq ($(OS), Darwin)
	$(CC) $(CFLAGS) $(OBJ_T) $(EXEC) -o $(PATH_TO_TESTS)$(EXEC_T) -lgtest -lgtest_main
	
else
	$(CC) $(CFLAGS) $(OBJ_T) $(EXEC) -o $(PATH_TO_TESTS)$(EXEC_T) -lgtest -lgtest_main -lpthread
endif
	$(PATH_TO_TESTS)./$(EXEC_T)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

valgrind: test
	$(V_COMMAND) ./$(PATH_TO_TESTS)$(EXEC_T)

leaks: test
	$(L_COMMAND) ./$(PATH_TO_TESTS)$(EXEC_T)

format-check:
	@cp ../materials/linters/.clang-format ./
	@clang-format -n *.h $(PATH_TO_FUNCTIONS)*.cpp $(PATH_TO_TESTS)*.cpp #$(PATH_TO_TESTS)*.h
	@rm .clang-format

format:
	@cp ../materials/linters/.clang-format ./
	@clang-format -i *.h $(PATH_TO_FUNCTIONS)*.cpp $(PATH_TO_TESTS)*.cpp #$(PATH_TO_TESTS)*.h
	@rm .clang-format

cppcheck:
	@cppcheck --enable=all --language=c++ --suppress=unusedFunction --suppress=missingIncludeSystem $(PATH_TO_FUNCTIONS)*.cpp $(PATH_TO_FUNCTIONS)*.h $(PATH_TO_TESTS)*.cpp $(PATH_TO_TESTS)*.h

s21_matrix_gcov.a: clean
	$(CC) $(CFLAGS) $(GCOVFLAGS) -c $(FILES)
	ar rc s21_matrix_gcov.a *.o
	ranlib s21_matrix_gcov.a

gcov_report: s21_matrix_gcov.a
	$(CC) $(CFLAGS) $(GCOVFLAGS) $(PATH_TO_TESTS)*.cpp s21_matrix_gcov.a $(TEST_LIBS) -o s21_matrix_gcov -lgtest -lgtest_main
	./s21_matrix_gcov
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory report
	rm -rf *.gcda *.gcno
	open report/index.html

clean:
	@rm -rf $(PATH_TO_FUNCTIONS)*.o $(EXEC) $(PATH_TO_TESTS)*.o $(PATH_TO_TESTS)./$(EXEC_T)
	@rm -rf $(PATH_TO_FUNCTIONS)*.gcno && rm -rf $(PATH_TO_FUNCTIONS)*.gcda
	@rm -rf $(PATH_TO_FUNCTIONS)*.info && rm -rf $(PATH_TO_FUNCTIONS)*.gcov
	@rm -rf $(PATH_TO_TESTS)*.gcda $(PATH_TO_TESTS)*.gcno
	@rm -rf $(PATH_TO_TESTS)*.gcda $(PATH_TO_TESTS)*.gcno
	@rm -rf RESULT_VALGRIND.txt gcov_*
	@rm -rf s21_matrix_gcov
	@rm -rf s21_matrix_gcov.a
	@rm -rf $(COV_REPORT)


