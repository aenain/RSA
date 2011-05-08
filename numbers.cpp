#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "numbers.h"
using namespace std;

bignum & Numbers::coprime_for(const bignum & n) {
	bignum * number = new BigUnsigned();
	bignum one(1);

	while( true ) {
		*number = random(one + 1, n - 1);

		if (gcd(n, *number) == one)
			break;
	}

  return *number;
}
 
bignum & Numbers::random(const bignum & first, const bignum & last) {
	integer first_length = length(first);
	integer last_length = length(last);
	bignum * number = new BigUnsigned();

	if (first_length < last_length - 2) // e.g. 1, 1000 :)
		*number = random( rand_in_range(first_length + 1, last_length - 1) );
	else {} // TODO!

	return *number;
}

bignum & Numbers::random(const integer first, const bignum & last) {
	bignum first_number(first);
	return random(first_number, last);
}

bignum & Numbers::random(const integer & length) {
	integer possible_last_digit[4] = { 1, 3, 7, 9 };
	// for checking division by 11 and 3
	long_integer sum_odd = 0;
	long_integer sum_even = 0;

	integer digit;
	string digits;

	digit = possible_last_digit[ rand_in_range(0, 3) ];
	digits.insert( digits.begin(), to_char(digit) ); // last digit

	for(integer i = 2; i < length; i++) {
		digit = rand() % 10;

		if (i % 2 == 0) sum_even += digit;
		else sum_odd += digit;

		digits.insert( digits.begin(), to_char(digit) );
	}

	// for first digit
	long_integer sum_for_3 = sum_even + sum_odd;
	long_integer diff_for_11 = abs(sum_even - sum_odd);

	digit = 1;

	while( (sum_for_3 + digit) % 3 == 0 || (diff_for_11 + digit) % 11 == 0)
		digit = rand_in_range(1, 9);

	digits.insert( digits.begin(), to_char(digit) );

	bignum * number = new BigUnsigned( stringToBigUnsigned(digits) );
	return * number;
}

integer Numbers::length(const bignum & n) {
	return to_s(n).length();
}

string & Numbers::to_s(const bignum & n) {
	string * digits = new string();
	* digits = bigUnsignedToString(n);
	return * digits;
}

integer Numbers::rand_in_range(integer first, integer last) {
	return first + rand() % (last - first + 1);
}

char Numbers::to_char(const integer & n) {
	return static_cast<char>(n + 48);
}
