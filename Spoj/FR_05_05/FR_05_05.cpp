#include <iostream>
#include <sstream>
using namespace std;

const int maxDigits = 1000000;
unsigned int cache[maxDigits];
const bool debug = false;

// count number of 'digit' long numbers that exist using the digits 1,2,3 where the modulo of two neighboring digits is equal to 1
void calc()
{
	cache[2] = 4;
	cache[3] = 6;
	for(unsigned int j = 4; j < maxDigits; ++j)
	{
		cache[j] = (cache[j-2] << 1) % 101010101;
		if(debug) cout << j << "->" << cache[j] << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	ostringstream oss;
	unsigned int tests;
	cin >> tests;
	calc();

	for(unsigned int i = 0; i < tests; ++i)
	{
		unsigned int digits;
		cin >> digits;
		oss << cache[digits] << '\n';
	}
	cout << oss.str();

	return 0;
}
