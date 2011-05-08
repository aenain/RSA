#include <iostream>
#include <string>
#define abs(A) ((A) >= 0) ? (A) : -(A)
using namespace std;

int main (int argc, char const* argv[])
{
  string digits;
  
  char digit = static_cast<char>(4 + 48);
  digits.insert(digits.begin(), digit);
  digit = static_cast<char>(5 + 48);
  digits.insert(digits.begin(), digit);
  cout << digits << endl;
  return 0;
}
