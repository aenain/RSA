#include <iostream>
#include "io.h"
using namespace std;

key_pair IO::read_key(const string & filename) {
	Numbers numbers;
	string number;
	key_pair pair;
	ifstream key_file(filename.c_str(), ios::in);

	if (key_file.good()) {
		for (integer i = 0; i < 2; i++) {
			getline(key_file, number);
			pair.push_back( stringToBigUnsigned(number) );
		}

		key_file.close();
	} else {} // TODO!

	return pair;
}

void IO::write_key(const string & filename, const bignum & n, const bignum & e) {
	Numbers numbers;
	ofstream key_file(filename.c_str(), ios::out);

	if (key_file.good()) {
		key_file << numbers.to_s(n) << endl << numbers.to_s(e);
		key_file.close();
	} else {} // TODO!
}
