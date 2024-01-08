CC=g++

.PHONY: args_task matrix clean

args_task: task_args.o
	g++ task_args.o -o args_task
	./args_task hello 'i`am' from std-in

task_args.o: task_args.cpp
	g++ -c task_args.cpp

clean:
	rm -rf *.o args_task

matrix:
	cmake -B build . && cd ./build && make && cd .. && cat input_matrix.txt | ./build/matrix

