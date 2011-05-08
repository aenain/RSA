#ifndef IO_H
#define IO_H

#include <iostream>
#include <string>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include "numbers.h"
using namespace std;

class IO {
	public:
		key_pair read_key(const string & filename);
		void write_key(const string & filename, const key_pair & pair);
};

#endif
