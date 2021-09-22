RPATH := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))

.SILENT:
.PHONY: all clean init

all: build/*.so build/*.a

init:
	if [ $(shell ./shell-check $(RPATH); echo $$?) -ne 0 ]; then \
		echo "Error: Current directory is not Makefile directory"; \
		exit 1; \
	fi

	mkdir build -p
	./export-vars

build/*.so: init
	./compile-libs -c ${SHARED_CFG}

build/*.a: init
	./compile-libs -c ${STATIC_CFG}

clean:
	rm -rf build
