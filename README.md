# cpp-control-freak
This is a template. A generic starting point for a cpp repo. Absolutely paranoid about style and safety and cleanliness in general.
The homework [description](https://docs.google.com/document/d/1vFZkZ5bA1FIVR2LqerlN2Zq71Uu84auAXmgszdNiBTU/edit?tab=t.0#heading=h.ovxdy8vfqydg)
dictates that we set up the basics first
## Tasks:
| Tools          | Implemented       |
|----------------|-------------------|
| Clang Compiler | :white_check_mark: |
| Google Test    | :white_check_mark:|
| vcpkg          | :white_check_mark: |
| ClangFormat    | :white_check_mark: |
| ClangTidy      | :white_check_mark: |
| gcov           | Ren is on it!     |
| CircleCI       | :white_check_mark: |

## Message to my dear, dear teammates:
 Ren: I am running this using Clion IDE on a Ubuntu machine, careful if you are on Mac/VSCode!

 How to setup:

 run 
```bash
./setup_vcpkg.sh
```
to clone vcpkg, install gtest and put it in your local repository

to build and run:
```bash
cmake -B build -S . --preset debug
cmake --build build
cd build && ctest
cd -
```

for coverage in html run:
```bash
cmake -B build -DENABLE_COVERAGE=ON
cmake --build build
cd build
ctest
make coverage
lcov --capture --directory . --output-file coverage.info --ignore-errors inconsistent
genhtml coverage.info --output-directory coverage_report
```
this makes a directory called coverage_report, then under v1 there are a bunch of html files to readily see cov