CC=c++
CFLAGS=-Wall --std=c++11 -O2
NAME=ADTbag
DEPS=ADTbag.hpp BSTree.hpp
OBJ=main.o

TEST_NAME=test_bst
TEST_OBJ=test_bst.o

all: $(OBJ) test executable clean
	
test: $(TEST_OBJ) test_exe clean_test run_test remove_test

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

executable:
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) 

test_exe:
	$(CC) -o $(TEST_NAME) $(TEST_OBJ) $(CFLAGS)

run_test:
	echo "SHOULD EQUAL 23" >/dev/null
	./$(TEST_NAME) | grep Key: | wc -l
	echo "NEXT LINE SHOULD BE BLANK" >/dev/null
	./$(TEST_NAME) | grep Key: | tee output | sort >./output2 && diff output output2
	rm ./output ./output2

clean:
	rm $(OBJ)

clean_test:
	rm $(TEST_OBJ)

remove:
	rm $(NAME)

remove_test:
	rm $(TEST_NAME)
