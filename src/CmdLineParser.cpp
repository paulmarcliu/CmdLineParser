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

#include "CmdLineParser.hpp"


CCmdLineParser::CCmdLineParser (int &argc, char **argv){
    for (int i=1; i < argc; ++i)
        this->tokens.push_back(std::string(argv[i]));
}

const std::string CCmdLineParser::getCmdOption(const std::string &option) const{
    std::vector<std::string>::const_iterator itr;
	for (itr = this->tokens.begin(); itr < this->tokens.end(); ++itr){
		std::size_t found = itr->find(option);
		if (found != std::string::npos){
			if ((itr + 1) < this->tokens.end()){
    			return *(++itr);
			}
		}
	}
    static const std::string empty_string("");
    return empty_string;
}

bool CCmdLineParser::cmdOptionExists(const std::string &option) const{
    std::vector<std::string>::const_iterator itr;
	for (itr = this->tokens.begin(); itr < this->tokens.end(); itr++){
		std::size_t found = itr->find(option);
		if (found != std::string::npos)
			return true;
	}
	return false;
}

