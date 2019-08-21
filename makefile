.PHONY : clean

BINPATH  =./bin/
DOCPATH  =./doc/
INCPATH  =./inc/
LIBPATH  =./lib/
SRCPATH  =./src/
TESTPATH =./test/
COVPATH  =./doc/coverageReport/

CC			= gcc
CFLAGS      = -Wall -g -pedantic
OBJS		= $(BINPATH)main.o $(BINPATH)functions.o
SRC_NAME	= main
TEST_NAME	= tests
TESTS_OBJ	= $(BINPATH)tests.o $(BINPATH)functions.o $(BINPATH)functions_test.o
ODFLAGS		= -CprsSx --prefix-addresses

all: $(BINPATH)$(SRC_NAME)
	objdump $(ODFLAGS) $(BINPATH)$(SRC_NAME) > $(DOCPATH)$(SRC_NAME)_objdump.txt

$(BINPATH)$(SRC_NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(BINPATH)$(SRC_NAME).o: $(SRCPATH)$(SRC_NAME).c
	$(CC) $(CFLAGS) -c $< -o $@

# Copy-paste this rule for every .c you have in the src folder, except main.c
$(BINPATH)functions.o: $(SRCPATH)functions.c
ifeq ($(MAKECMDGOALS),check)
	$(CC) $(CFLAGS) -c $< -o $@ --coverage
else
	$(CC) $(CFLAGS) -c $< -o $@ 
endif

check: $(BINPATH)$(TEST_NAME)
	$(BINPATH)$(TEST_NAME) 2>&1 | tee $(DOCPATH)$(TEST_NAME).txt
	gcov -b $(BINPATH)$(TEST_NAME)
	lcov --capture --directory $(BINPATH) --output-file $(DOCPATH)coverage.info
	genhtml $(DOCPATH)coverage.info --output-directory $(COVPATH)

$(BINPATH)$(TEST_NAME): $(TESTS_OBJ)
	$(CC) $(CFLAGS) $(TESTS_OBJ) -o $@ -O0 -lcunit --coverage

$(BINPATH)$(TEST_NAME).o: $(TESTPATH)$(TEST_NAME).c
	$(CC) $(CFLAGS) -c $< -o $@

# Copy-paste this rule for every .c you have in the test folder, except tests.c
$(BINPATH)functions_test.o: $(TESTPATH)functions_test.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(BINPATH)*.bin $(BINPATH)*.o $(BINPATH)*.elf $(BINPATH)*.lst $(DOCPATH)*.txt *.map $(BINPATH)*.gcda $(BINPATH)*.gcno $(DOCPATH)*.info $(COVPATH)*.png $(COVPATH)*.css $(COVPATH)*.html $(COVPATH)src/*.html $(COVPATH)test/*.html $(BINPATH)$(SRC_NAME) $(BINPATH)$(TEST_NAME)