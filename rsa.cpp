#include <iostream>
#include <string>
#include <cstring>
#include "cipher.h"
#include "key_pair_generator.h"
using namespace std;

// argv[0] - name of executable file of this program
// argv[1] - mode of program:
// --generate-keys - generating keys
// --decode - decoding using id_rsa (requires filename)
// --code - coding using id_rsa.pub (requires filename)
// argv[2] - name of source file (if needed)
// argv[3] - name of destination file (if needed)

int main (int argc, char const* argv[])
{
	srand( time(NULL) );

	Numbers numbers;
	Prime prime;
	cout << prime.generate_prime(40) << endl;

	if (argc == 2) {
		if (!strcmp(argv[1], "--generate-keys")) {// generates keys and saves to id_rsa.pub i id_rsa in current folder
			KeyPairGenerator generator(100);
			generator.generate();
		}
	}
	else if (argc == 4) {
		string source(argv[2]), destination(argv[3]);
		Cipher cipher(source, destination);

		if (!strcmp(argv[1], "--code")) {// codes using public key from id_rsa.pub
			cipher.encrypt();
		}
		else if (!strcmp(argv[1], "--decode")) {// decodes using private key from id_rsa
			cipher.decrypt();
		}
		else
			cout << "Unknown argument." << endl;
	}
	else {
		cout << "Wrong number of arguments." << endl;
	}

	return 0;
}
