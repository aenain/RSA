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
		static key_pair read_key(const string & filename);
		static void write_key(const string & filename, const bignum & n, const bignum & e);
};

#endif
