# Not to print any recipes before executing them
.SILENT:

# Settings
BUILD = _build
TESTS_CONCURRENCY = 8

all: main

main:
	cd "${BUILD}" && ./main

test:
	cd "${BUILD}" && CTEST_PARALLEL_LEVEL=${TESTS_CONCURRENCY} make test

# CMake
cmake-clean:
	rm -rf "${BUILD}"

cmake-generate:
	cmake -B "${BUILD}" .

cmake-build:
	cmake --build "${BUILD}"
