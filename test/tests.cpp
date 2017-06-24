/**The MIT License (MIT)

Copyright (c) 2017 Paul Marc Liu (paul.marc.liu@gmail.com)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#include <gtest/gtest.h>
#include "CmdLineParser.hpp"

// Maximum String length for the argv parameter test 
#define MAX_STRING_LEN 32

// Quick and dirty way to know the number of params in the test string - not in the code 
#define NUM_ARGS_IN_ARRAY(x)	sizeof(x)/sizeof(x[0])


// To use a test fixture, derive a class from testing::Test.
class CmdLineParserTest : public testing::Test {
 	protected:  // You should make the members protected s.t. they can be
             // accessed from sub-classes.

  	// virtual void SetUp() will be called before each test is run.  You
  	// should define it if you need to initialize the varaibles.
  	// Otherwise, this can be skipped.
  	virtual void SetUp() {
  	}

  	// virtual void TearDown() will be called after each test is run.
  	// You should define it if there is cleanup work to do.  Otherwise,
  	// you don't have to provide it.
  	//
   	virtual void TearDown() {
   	}

	void TestCmdOptionExists(char cmdline[][MAX_STRING_LEN], int argc, std::string option){
		char **param = new char*[argc];
		for (int i=0; i<argc; i++){
			param[i] = &cmdline[i][0];
		}
		CCmdLineParser input(argc, param);
		ASSERT_TRUE(input.cmdOptionExists(option));
		delete[] param;
    }
    
    void TestgetCmdOption(char cmdline[][MAX_STRING_LEN], int argc, std::string option, std::string option_value){
		char ** param = new char*[argc];
		std::string decoded_option;
		for (int i=0; i<argc; i++){
			param[i] = &cmdline[i][0];
		}
		CCmdLineParser input(argc, param);
		decoded_option = input.getCmdOption(option);
		ASSERT_TRUE(decoded_option.compare(option_value) == 0);
		delete[] param;
    }
public:
  	// test argv values (hand-craft this line to suit tests)
  	char test_cmdline2[2][MAX_STRING_LEN]={"test", "-h"};
	char test_cmdline3[4][MAX_STRING_LEN]={"test", "-h", "-i", "input.doc"};
	char test_cmdline4[6][MAX_STRING_LEN]={"test", "-h", "-i", "input.doc", "-o", "output.doc"};
	char test_cmdline5[8][MAX_STRING_LEN]={"test", "-h", "-i", "input.doc", "-o", "output.doc", "-p", "portnum"};
};

// Test fixture to determine whether the command option exists
TEST_F(CmdLineParserTest, TestCmdOptionExists){
  TestCmdOptionExists(test_cmdline2, NUM_ARGS_IN_ARRAY(test_cmdline2), std::string("-h"));	// detect -h
  
  TestCmdOptionExists(test_cmdline3, NUM_ARGS_IN_ARRAY(test_cmdline3), std::string("-h"));	// detect -h
  TestCmdOptionExists(test_cmdline3, NUM_ARGS_IN_ARRAY(test_cmdline3), std::string("-i"));	// detect -i
  
  TestCmdOptionExists(test_cmdline4, NUM_ARGS_IN_ARRAY(test_cmdline4), std::string("-h"));	// detect -h
  TestCmdOptionExists(test_cmdline4, NUM_ARGS_IN_ARRAY(test_cmdline4), std::string("-i"));	// detect -i
  TestCmdOptionExists(test_cmdline4, NUM_ARGS_IN_ARRAY(test_cmdline4), std::string("-o"));	// detect -o
  
  TestCmdOptionExists(test_cmdline5, NUM_ARGS_IN_ARRAY(test_cmdline5), std::string("-h"));	// detect -h
  TestCmdOptionExists(test_cmdline5, NUM_ARGS_IN_ARRAY(test_cmdline5), std::string("-i"));	// detect -i
  TestCmdOptionExists(test_cmdline5, NUM_ARGS_IN_ARRAY(test_cmdline5), std::string("-o"));	// detect -o
  TestCmdOptionExists(test_cmdline5, NUM_ARGS_IN_ARRAY(test_cmdline5), std::string("-p"));	// detect -p
}

// Test fixture to determine whether the right command option is being decoded
TEST_F(CmdLineParserTest, TestgetCmdOption){
  TestgetCmdOption(test_cmdline3, NUM_ARGS_IN_ARRAY(test_cmdline3), std::string("-i"), std::string("input.doc"));	// detect -i
  
  TestgetCmdOption(test_cmdline4, NUM_ARGS_IN_ARRAY(test_cmdline4), std::string("-i"), std::string("input.doc"));	// detect -i
  TestgetCmdOption(test_cmdline4, NUM_ARGS_IN_ARRAY(test_cmdline4), std::string("-o"), std::string("output.doc"));	// detect -o

  TestgetCmdOption(test_cmdline5, NUM_ARGS_IN_ARRAY(test_cmdline5), std::string("-i"), std::string("input.doc"));	// detect -i
  TestgetCmdOption(test_cmdline5, NUM_ARGS_IN_ARRAY(test_cmdline5), std::string("-o"), std::string("output.doc"));	// detect -o
  TestgetCmdOption(test_cmdline5, NUM_ARGS_IN_ARRAY(test_cmdline5), std::string("-p"), std::string("portnum"));	// detect -p
}

