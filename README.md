# RectalCrypt

Yet another thermorectal cryptanalyzer.

## Building

This project and C++ Requests both use CMake. The first step is to make sure all of the submodules are initialized:

```
git submodule update --init --recursive
```

Then make a build directory and do a typical CMake build from there:

```
mkdir build
cd build
cmake ..
make
```

This should produce a binary in the build directory called `RectalCrypt`. Run it! The program you just ran is a sweet 3 liner you'll find [here](https://github.com/coolanole/rectalcrypt/blob/master/main.cpp).

## Requirements

The only explicit requirement is a C++11 compatible compiler such as clang or gcc. The minimum required version of gcc is unknown, so if anyone has trouble building this library with a specific version of gcc, do let me know.