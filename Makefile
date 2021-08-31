.PHONY: format
format:
	clang-format src/* -i

.PHONY: build
build:
	mkdir -p build 	
	cd build && \
	cmake .. && \
	make 

