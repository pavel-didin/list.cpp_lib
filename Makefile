CC=g++
CFLAGS= -Wall -g -fprofile-arcs -ftest-coverage

all: tests
tests.o: tests.cpp
	${CC} -c tests.cpp -o tests.o ${CFLAGS}
list.o: list.cpp
	${CC} -c list.cpp -o list.o ${CFLAGS}
tests: tests.o list.o
	${CC} list.o tests.o -o tests ${CFLAGS}
clean:
	@rm -rf *.o *.gcno *.gcda *.gcov tests 2&>/dev/null
tar:
	tar czvf ../list_cpp.tgz ../list_cpp
