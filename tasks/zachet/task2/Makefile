.PHONY: test build

config:
	cmake -B ./build -DCMAKE_BUILD_TYPE=Release

build: config
	cmake --build ./build --target  all  --config Release

run: build zachet_task2
	rm -f file1.txt file2.txt
	./zachet_task2

clean:
	rm -rf build/ zachet_task2

	