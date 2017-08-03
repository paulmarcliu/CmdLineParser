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

#include <iostream>
#include "CmdLineParser.hpp"

void showUsage(char *exec_name){
	std::cout << "Usage:" << exec_name << " [-h] [-p can0]\n";
	std::cout << "-h - help screen shown \n";
	std::cout << "-p - port name i.e. can0 or vcan0\n";
	std::cout << "-i - input file name\n";
	std::cout << "-o - output file name\n";
}

int main(int argc, char **argv){
    CCmdLineParser input(argc, argv);
    if((input.cmdOptionExists("-h")) || (argc < 2)){
    	showUsage(argv[0]);
    	return 0;
    }
    
    const std::string &in_filename = input.getCmdOption("-i");
    if (!in_filename.empty()){
    	std::cout << "input file " << in_filename << std::endl;
    }
    const std::string &out_filename = input.getCmdOption("-o");
    if (!out_filename.empty()){
    	std::cout << "output file " << out_filename << std::endl;
    }
    const std::string &portname = input.getCmdOption("-p");
    if (!portname.empty()){
    	std::cout << "portname " << portname << std::endl;
    }
	return 0;
}
