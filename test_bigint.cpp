#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include "bigint/BigIntegerLibrary.hh"

using std::ofstream;
using std::ifstream;
using std::ios;


int main() {
  BigUnsigned a(100), b(83), q;
  std::string input;
  a.divideWithRemainder(b, q); // a %= b; q = a/b
  //std::cout << a << ' ' << b << std::endl;
  //ofstream out("para.txt", ios::out);
  //out << a << ' ' << b;
  //out.close();
  ifstream in("para.txt", ios::in);
  in >> input;
  a = stringToBigUnsigned(input);
  unsigned long long int position = in.tellg();
  in.seekg( position++ ); // to ommit whitespace
  in >> input;
  b = stringToBigUnsigned(input);

  //std::vector<std::string> numbers;
  //boost::split(numbers, input, boost::is_any_of(" "));
  //b = stringToBigUnsigned(numbers[0]);
  //a = stringToBigUnsigned(numbers[1]);
  std::cout << b << ' ' << a << std::endl;
  return 0;
}
