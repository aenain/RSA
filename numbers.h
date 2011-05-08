#ifndef NUMBERS_H
#define NUMBERS_H

#include <iostream>
#include <vector>
#include "bigint/BigIntegerLibrary.hh"
using namespace std;

typedef unsigned int integer;
typedef long long int long_integer;
typedef BigUnsigned bignum;
typedef vector<bignum> key_pair;

class Numbers {
	public:
		bignum & coprime_for(const bignum & n);
		bignum & random(const bignum & first, const bignum & last);
		bignum & random(const integer first, const bignum & last);
		bignum & random(const integer & length); // returns random number which is not divisible by 2,3,5,11 :)
		integer length(const bignum & n);
		string & to_s(const bignum & n);
		char to_char(const integer & n);

	private:
		integer rand_in_range(integer first, integer last);
};

#endif
