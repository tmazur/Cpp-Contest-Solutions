#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const bool debug = false;

template<typename T>
inline bool fastIoInt(T *a)
{
    register char c=0;
    while (c<33 && c != EOF) c=getchar_unlocked();
	if(c==EOF)
		return false;
    *a=0;
    while (c>33)
    {
        *a=*a*10+c-'0';
        c=getchar_unlocked();
    }
	return true;
}

const int SIZE = 10000000;
bool candles[SIZE] = {false};
unsigned long lastBlownOutSlowButSure(unsigned long n)
{
	memset(candles, 0, sizeof(candles));
	unsigned long count = 0;
	for(unsigned long i = 0; i < n-1; ++i)
	{
		while(candles[count]) count = (count + 1) % n; // find first not blown out candle...
		count = (count + 1) % n; // and skip it
		while(candles[count]) count = (count + 1) % n; // find second not blown out candle...
		candles[count] = true; // and blow it out

	}

	// find the candle that is not blown out
	for(unsigned long i = 0; i < n; ++i)
	{
		if(!candles[i]) return i+1;
	}
	return 0;
}

unsigned long lastBlownOut(unsigned long n)
{
	// if n is a power of 2 the remaining candle will be number 1 (counting from 1, not 0)
	// otherwise find the maximum number P, where P < n, and P is a power of 2
	// the answer will be 1 + 2 *(n-P)
	unsigned long powerOf2 = 0; // round down number of candles to closest power of 2
	unsigned long temp = n;
	while(temp != 1)
	{
		temp >>= 1;
		powerOf2++;
	}
	unsigned long P = pow(2, powerOf2);
	return 1 + 2 * (n-P);
}

int main() {
	ios_base::sync_with_stdio(false);
	unsigned long tests;
	fastIoInt<unsigned long>(&tests);

	for(unsigned long t = 0; t < tests; ++t)
	{
		unsigned long n;
		fastIoInt<unsigned long>(&n);
		printf("%d\n", lastBlownOut(n));
		// printf("%d\n", lastBlownOutSlowButSure(n));
	}
	return 0;
}
