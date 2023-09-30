.PHONY: test build

config:
	cmake -B ./build -DCMAKE_BUILD_TYPE=debug

build: config
	cmake --build ./build --target all

test: build build/tests_run
	build/tests_run

clean:
	rm -rf build/