#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#define abs(A) ((A) >= 0) ? (A) : -(A)
using namespace std;

string block_from_char(const char letter) {
	int ascii = static_cast<int>(letter);

	char * tmp = new char[3];
	sprintf(tmp, "%d", ascii);

	string block(tmp);

	while (block.length() < 3)
		block.insert( block.begin(), '0' );

	return block;
}

int main (int argc, char const* argv[])
{
  string digits;
  
  char digit = static_cast<char>(4 + 48);
  digits.insert(digits.begin(), digit);
  digit = static_cast<char>(5 + 48);
  digits.insert(digits.begin(), digit);
  cout << digits << endl;
  
  char mark = 'a';
  cout << static_cast<int>(mark) << endl;
  cout << block_from_char(mark) << endl;

	string napis = "text";
	napis.erase( napis.begin() );
	cout << napis << endl;

	string liczba = "068";
	cout << atoi(liczba.c_str()) << endl;
	cout << static_cast<char>(68) << endl;
  return 0;
}
