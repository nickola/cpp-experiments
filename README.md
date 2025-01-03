# C/C++ Experiments

Simple C/C++ application with `cmake` configuration (see `CMakeLists.txt`) and concurrent tests execution (`ctest`, `GoogleTest`).

## Building

```shell
make cmake-generate cmake-build
```

Output:
```
-- The CXX compiler identification is AppleClang 16.0.0.16000026
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
...
-- Detecting CXX compile features
-- Detecting CXX compile features - done
...
-- [download 100% complete]
-- The C compiler identification is AppleClang 16.0.0.16000026
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
...
-- Detecting C compile features
-- Detecting C compile features - done
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD - Success
-- Found Threads: TRUE
-- Configuring done (1.7s)
-- Generating done (0.0s)
-- Build files have been written to: cpp-experiments/_build
[  7%] Building CXX object CMakeFiles/main.dir/source/main.cpp.o
[ 14%] Building CXX object CMakeFiles/main.dir/library/utilities.cpp.o
[ 21%] Linking CXX executable main
[ 21%] Built target main
[ 28%] Building CXX object _deps/googletest-build/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
[ 35%] Linking CXX static library ../../../lib/libgtest.a
[ 35%] Built target gtest
[ 42%] Building CXX object _deps/googletest-build/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o
[ 50%] Linking CXX static library ../../../lib/libgtest_main.a
[ 50%] Built target gtest_main
[ 57%] Building CXX object CMakeFiles/gtest_utilities.dir/tests/gtest_utilities.cpp.o
[ 64%] Building CXX object CMakeFiles/gtest_utilities.dir/library/utilities.cpp.o
[ 71%] Linking CXX executable gtest_utilities
[ 71%] Built target gtest_utilities
[ 78%] Building CXX object _deps/googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o
[ 85%] Linking CXX static library ../../../lib/libgmock.a
[ 85%] Built target gmock
[ 92%] Building CXX object _deps/googletest-build/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o
[100%] Linking CXX static library ../../../lib/libgmock_main.a
[100%] Built target gmock_main
```

## Running tests concurrently

```shell
make test
```

Each test will call `sleep(5)`, with concurrent execution (`CTEST_PARALLEL_LEVEL=8`) it should take ~5-6 seconds.

Output:
```
Running tests...
Test project cpp-experiments/_build
    Start 1: gtest_utilities.wait1
    Start 2: gtest_utilities.wait2
    Start 3: gtest_utilities.wait3
    Start 4: ctest_success
    Start 5: ctest_error
1/5 Test #1: gtest_utilities.wait1 ............   Passed    5.05 sec
2/5 Test #2: gtest_utilities.wait2 ............   Passed    5.05 sec
3/5 Test #3: gtest_utilities.wait3 ............   Passed    5.05 sec
4/5 Test #4: ctest_success ....................   Passed    5.36 sec
5/5 Test #5: ctest_error ......................   Passed    5.36 sec

100% tests passed, 0 tests failed out of 5

Total Test time (real) =   5.36 sec
```


## Running application

```shell
make
```

Output:
```
C/C++ Experiments
Usage: main <argument>
If "argument" is 0, output is "SUCCESS". Otherwise, output is "ERROR".
```
