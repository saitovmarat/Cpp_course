.PHONY: test build

config:
	cmake -B ./build -DCMAKE_BUILD_TYPE=Release

build: config
	cmake --build ./build --target all --config Release

run: build zachet_task1
	./zachet_task1

test: build zachet_task1
	./tests_run
	rm -f test_books_data.txt

clean:
	rm -rf build/ zachet_task1 tests_run test_books_data.txt
