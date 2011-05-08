#ifndef CIPHER_H
#define CIPHER_H

#include <iostream>
#include "prime.h"
#include "io.h"

using namespace std;

class Cipher {
	public:
		void encrypt();
		void decrypt();
		Cipher(const string & source, const string & destination) : source_path(source), destination_path(destination) {};

	private:
		string source_path, destination_path;
		string block_from_char(const char letter);
		char char_from_block(const string & block);
};

#endif
