.PHONY: test build

config:
	cmake -B ./build -DCMAKE_BUILD_TYPE=debug

build: config
	cmake --build ./build --target all

test: build build/fixed_size_stack
	build/fixed_size_stack

clean:
	rm -rf build/