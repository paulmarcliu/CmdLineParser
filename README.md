# C/C++ Command Line Parser utility function
Update:  8/3/17.
Noticed that the gtest executable was not being produced.  The cmake file was not
configured to produce both the executable and the gtest executable.  I must have 
checked in the wrong version.  The gtest executable is CmdLineParser_test and the 
executable is CmdLineParser.

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


# How to install gtest in a few keystrokes

Step 1:  Download from github
cd ~
git clone https://github.com/google/googletest.git

Step 2: Configure tests
cd ~/googletest
mkdir build
cd ~/googletest/build
cmake ..

Step 3:  Build libraries
make

Step 4:  Install libraries - need sudo
sudo make install


This should have installed the shared libraries in /usr/local/lib by default
