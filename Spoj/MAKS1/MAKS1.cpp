#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

inline bool fastIoULong(unsigned long *a)
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
	unsigned long ones = 0, twos = 0, mask = 0 ;
	ios_base::sync_with_stdio(false);
	unsigned long temp = 0;
	// while(cin >> temp) // 2.82s
	while(fastIoULong(&temp)) // 0.16s fast IO is fast...
	{
		twos  |= ones & temp;
		ones  ^= temp;
		mask = ~(ones & twos);
		ones &= mask;
		twos &= mask;
	}
	printf("%d\n", (ones | twos));
	return 0;
}
