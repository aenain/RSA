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
		Cipher(const string & source, const string & destination) : source(source), destination(destination) {};
	private:
		string source, destination;
};

#endif
