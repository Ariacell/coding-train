Little repo for holding experiments in c++/leetcode that I do

## Build & run tests
```sh
cmake -G Ninja -DCMAKE_BUILD_TYPE=DEBUG -B build -S .
cmake --build build
cd build && ctest
# Format with
cmake --build build --target format   
```

## Adding a question
Add a subdirectory, ensure to add it to the root cmakelists, and add relevant files to the tests target for that directory in the nested CMakeLists.txt. Then building and running should discover those new tests and run as part of the overall solution.
