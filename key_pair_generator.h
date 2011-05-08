#ifndef KEY_PAIR_GENERATOR_H
#define KEY_PAIR_GENERATOR_H

#include <iostream>
#include "prime.h"
#include "io.h"
using namespace std;

class KeyPairGenerator {
	public:
		void generate();
		KeyPairGenerator(const integer & length) : length(length), private_key_path("id_rsa"), public_key_path("id_rsa.pub") {};

	private:
		integer length;
		string private_key_path;
		string public_key_path;
};

#endif
