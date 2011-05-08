#ifndef PRIME_H
#define PRIME_H

#include <iostream>
#include "numbers.h"

class Prime {
	public:
		bool primality_test(const bignum & n, const integer & accuracy);
		bignum & generate_prime(const integer & length);
};

#endif
