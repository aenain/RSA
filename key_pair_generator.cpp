#include <iostream>
#include "key_pair_generator.h"
using namespace std;

void KeyPairGenerator::generate() {
	Prime prime;
	Numbers numbers;

	cout << "Generating p..." << endl;
	bignum p( prime.generate_prime(length) );

	cout << "Generating q..." << endl;
	bignum q( prime.generate_prime(length) );

	cout << "Calculating n..." << endl;
	bignum n( p * q );

	bignum one(1);

	cout << "Computing fi(n)..." << endl;
	bignum fi_n( n - p - q + one ); // fi(n) = (p - 1)(q - 1) if p,q are prime numbers.

	cout << "Choosing e..." << endl;
	bignum e( numbers.coprime_for(fi_n) ); // 1 < e < fi(n) and gcd(e, fi(n)) = 1

	cout << "Computing d..." << endl;
	bignum d( modinv(e, fi_n) );

	cout << "Saving private key..." << endl;
	IO::write_key( private_key_path, n, d ); // private

	cout << "Saving public key..." << endl;
	IO::write_key( public_key_path, n, e );

	cout << "Successfully done!" << endl;
	cout << "You can find your private key in file: `" << private_key_path << "` and public: `" << public_key_path << "`." << endl;
}
