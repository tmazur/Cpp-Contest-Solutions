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

int main() {
	ios_base::sync_with_stdio(false);
	unsigned long tests;
	fastIoInt<unsigned long>(&tests);

	for(unsigned long t = 0; t < tests; ++t)
	{
		unsigned long age1, pos1, age2, pos2;
		fastIoInt<unsigned long>(&age1);
		fastIoInt<unsigned long>(&pos1);

		fastIoInt<unsigned long>(&age2);
		fastIoInt<unsigned long>(&pos2);

		unsigned long diff = (pos1 > pos2) ? pos1 - pos2 : pos2 - pos1;

		// will cat1 win?
		bool cat1starts = age1 > age2;
		bool startingCatWins = (diff % 3 == 1) ? false : true;
		bool can1wins = (cat1starts && startingCatWins) || (!cat1starts && !startingCatWins);

		printf("%d\n", can1wins ? 1 : 0);
	}
	return 0;
}
