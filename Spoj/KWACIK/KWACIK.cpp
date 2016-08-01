#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

int solutions[37] = {1, 8, 34, 104, 259, 560, 1092, 1968, 3333, 5368, 8034, 11224, 14775, 18480, 22100, 25376, 28041, 29832, 30502, 29832, 28041, 25376, 22100, 18480, 14775, 11224, 8034, 5368, 3333, 1968, 1092, 560, 259, 104, 34, 8, 1};

int solve(int sum)
{
	int countSolutions = 0;
	for(int i1 = 0; i1 < 10; ++i1)
	for(int i2 = 0; i2 < 10; ++i2)
	for(int i3 = 0; i3 < 10; ++i3)
	for(int i4 = 0; i4 < 10; ++i4)
	for(int i5 = 0; i5 < 10; ++i5)
	for(int i6 = 0; i6 < 10; ++i6)
	for(int i7 = 0; i7 < 10; ++i7)
	for(int i8 = 0; i8 < 10; ++i8)
	for(int i9 = 0; i9 < 10; ++i9)
	{
		if(i1+i2+i4+i5 == sum && i2+i3+i5+i6 == sum && i4+i5+i7+i8 == sum && i5+i6+i8+i9 == sum)
		{
			++countSolutions;
		}
	}
	return countSolutions;
}

int main() {
	ios_base::sync_with_stdio(false);
	unsigned int tests;
	cin >> tests;

	for(unsigned int t = 0; t < tests; ++t)
	{
		unsigned int sum;
		cin >> sum;

		if(sum > 36)
		{
			cout << "0\n";
		}
		else
		{
			cout << solutions[sum] << "\n";
		}

	}
	return 0;
}
