#include <iostream>
#include <cstdlib>
#include "cipher.h"
using namespace std;

void Cipher::decrypt() {
	string line, blocks, letters;
	key_pair pair = IO::read_key("id_rsa"); // first is n, second (and last) is d
	bignum m;

	integer amount_of_blocks = ( bigUnsignedToString( pair.at(1) ).length() - 2 ) / 3;
	integer readed;

	ifstream source(source_path.c_str(), ios::in);
	ofstream destination(destination_path.c_str(), ios::out);

	if (source.good() && destination.good()) {
		while( getline(source, line) ) {
			if (line.length() < 1) continue;
			letters.clear();

			m = modexp( stringToBigUnsigned(line), pair.at(1), pair.at(0) );
			blocks = bigUnsignedToString(m);
			blocks.erase( blocks.begin() ); // remove '1' in front.
			readed = blocks.length() / 3;

			for( integer i = 0; i < readed; i++ )
				letters.append( 1, char_from_block(blocks.substr(i * 3, 3)) );

			destination << letters;
		}

		source.close();
		destination.close();

	} else {} // TODO!
}

void Cipher::encrypt() {
	key_pair pair = IO::read_key("id_rsa.pub"); // first is n, second (and last) is e
	integer amount_of_blocks = ( bigUnsignedToString( pair.at(1) ).length() - 2 ) / 3;

	char * letters = new char[amount_of_blocks];
	string blocks;
	integer readed;

	ifstream source(source_path.c_str(), ios::in);
	ofstream destination(destination_path.c_str(), ios::out);

	if (source.good() && destination.good()) {

		while (!source.eof()) {
			blocks = "1"; // to cover 0 in front of ascii code
			source.read(letters, amount_of_blocks);
			readed = source.gcount();

			for( integer i = 0; i < readed; i++ )
				blocks.append( block_from_char(letters[i]) );

			destination << bigUnsignedToString(modexp( stringToBigUnsigned(blocks), pair.at(1), pair.at(0) )) << endl;
		}

		source.close();
		destination.close();
	} else {} // TODO!
}

string Cipher::block_from_char(const char letter) {
	integer ascii = static_cast<integer>(letter);

	char * tmp = new char[3];
	sprintf(tmp, "%d", ascii);

	string block(tmp);

	while (block.length() < 3)
		block.insert( block.begin(), '0' );

	return block;
}

char Cipher::char_from_block(const string & block) {
	integer ascii = atoi(block.c_str());
	return static_cast<char>(ascii);
}
