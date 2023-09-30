all: build

rebuild: clean build

build: stackList.o
	g++ -Wall -Wextra -Werror stackList.o main.cpp -o main

stackList.o:
	g++ -c -Wall -Wextra -Werror stackList.cpp

clean:
	rm -rf *.o main