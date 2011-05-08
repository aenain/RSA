#include <iostream>
#include "prime.h"
using namespace std;

bool Prime::primality_test(const bignum & n, const integer & accuracy) {
	long_integer s = 0;
	bignum d(1);
	bignum a;
	bignum x;

	Numbers numbers;
	bignum n_minus_one(n - 1);
	bignum one(1);

	while ( n_minus_one % 2 == 0 ) {
		n_minus_one /= 2;
		s++;
	}

	d = n_minus_one;

	for(integer k = 0; k < accuracy; k++) {
		a = numbers.random(2, n - 1);
		x = modexp(a, d, n);

		if (x == one || x == n_minus_one) continue;

		for(long_integer r = 1; r <= s - 1; r++) {
			x = modexp(x, 2, n);

			if (x == one) return false;
			if (x == n_minus_one) continue;
		}

		return false;
	}

	return true; // possibly prime
}

bignum & Prime::generate_prime(const integer & length) {
	Numbers numbers;
	bignum * number = new BigUnsigned( numbers.random(length) );

	while ( !primality_test(*number, 4) )
		* number = numbers.random( length ); // or sth like: numbers.try_upgrading_to_prime( const bignum & number )

	return * number;
}
