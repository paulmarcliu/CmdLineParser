# C/C++ Command Line Parser utility function

This is a small C++ utility classed used to parse the command line argument list
and return the command line option parameter or just detect presence of the 
command line option.

Unit testing is done using GoogleTest.  Please install GoogleTest in order to compile
the unit tests.  Otherwise, comment out the relevant sections in CMakeList.txt.

Contents:
1.  CMakeLists.txt - cmake file that will compile both the unit test AND the sample
main executable.

2.  ./test - contains the GoogleTest unit test code.

3.  ./src - contains the CCmdLineParser class code - this can be included in the
but did not do this as I was experimenting with CMake and GoogleTest.

4.  ./include - include file for the CCmdLineParser class.

How To Build:
1.  mkdir build
2.  cd build
3.  cmake ..
4.  cmake --build . or make



