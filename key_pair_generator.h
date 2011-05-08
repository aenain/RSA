#ifndef KEY_PAIR_GENERATOR_H
#define KEY_PAIR_GENERATOR_H

#include <iostream>
#include "prime.h"
#include "io.h"

class KeyPairGenerator {
	public:
		void generate();
		KeyPairGenerator(const integer & length) : length(length) {};
	private:
		integer length;
};

#endif
