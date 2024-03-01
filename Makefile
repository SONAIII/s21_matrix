CC = gcc 

# lib 
TARGET = s21_matrix.a
SRC_DIR = ./
OBJ_DIR = ./obj
SRC:= $(wildcard *.c)
OBJ:= $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

# test
TEST_OBJ_DIR = ./test_files/obj
TEST_SRC_DIR = ./test_files
TEST_SRC = $(wildcard ./test_files/*.c)
TEST_OBJ = $(addprefix $(TEST_OBJ_DIR)/, $(notdir $(TEST_SRC:.c=.o)))
TEST_EXECUTABLE = test

# gcov
GCOV_TARGET = ./cov
GCOV_EXECUTABLE = gtest
GCOV_DIR = ./gcov
GCOV_LIB = gcov_s21_matrix.a
GCOV_OBJ = $(addprefix $(GCOV_DIR)/, $(notdir $(SRC:.c=.o)))
GCOV_INFO = cov.info

# flags
LIB = ar rcs
CFLAGS = -std=c11 -Wall -Werror -Wextra 
# TEST_LIBS = -lcheck
TEST_LIBS = -lcheck -lsubunit -lm
TEST_FLAGS = -g $(CFLAGS)
GCOV_FLAGS = -fprofile-arcs -ftest-coverage

# utils
RM = rm -f
DIR_DUP = mkdir -p 

all: test gcov_report clean

clean:
	@rm -rf ./gcov $(OBJ_DIR) $(TEST_OBJ_DIR) $(GCOV_LIB) $(GCOV_INFO) $(GCOV_EXECUTABLE) $(TEST_EXECUTABLE) $(TARGET) *.o

open:
	@open cov/index.html

gcov_report: $(GCOV_TARGET)
	@make open

# test linking

test: $(TARGET) $(TEST_OBJ)
	$(CC) $(TEST_OBJ) -o $(TEST_EXECUTABLE) $(TEST_LIBS)  $(TARGET)

test_gcov: $(GCOV_LIB) $(TEST_OBJ)
	$(CC) $(TEST_OBJ) $(GCOV_FLAGS) -o $(GCOV_EXECUTABLE) $(TEST_LIBS)  $(GCOV_LIB)

# lib linking

$(TARGET): $(OBJ)
	$(LIB)  $(TARGET) $(OBJ)

$(GCOV_LIB): $(GCOV_OBJ)
	$(LIB) $(GCOV_LIB) $(GCOV_OBJ)

# compiling

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP) $(OBJ_DIR)
	$(CC)  $(CFLAGS) -c -o $@ $<

$(TEST_OBJ_DIR)/%.o: $(TEST_SRC_DIR)/%.c
	$(DIR_DUP) $(TEST_OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(GCOV_DIR)/%.o: $(SRC_DIR)/%.c 
	$(DIR_DUP) $(GCOV_DIR)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) -o $@ -c $<

# gcov

$(GCOV_INFO): test_gcov
	./$(GCOV_EXECUTABLE)
	geninfo $(GCOV_DIR) -b . -o ./$(GCOV_INFO)

$(GCOV_TARGET): $(GCOV_INFO)
	genhtml $(GCOV_INFO) -o $(GCOV_TARGET)

garinbla_test:
	$(CC) -c s21_*.c
	ar rcs s21_matrix.a s21_*.o
	rm ./s21_*.o
# $(CC) -c test.c
	$(CC) -c test_files/*.c
	$(CC)  *.o $(TEST_LIBS)  s21_matrix.a   -o test
	rm -rf *.o

garinbla_single_test_case:
	$(CC) -o test *.c $(TEST_LIBS)

