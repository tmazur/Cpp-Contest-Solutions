#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <math.h>
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

inline double area(unsigned long a, unsigned long b, unsigned long c)
{
	double s = (a+b+c)/2.0;
	double area = s*(s-a)*(s-b)*(s-c);
	if(area > 0) return sqrt(area);
	return 0;
	return sqrt(area);
}

int main() {
	ios_base::sync_with_stdio(false);
	unsigned long tests;
	cin >> tests;
	for(unsigned long i = 0; i < tests; ++i)
	{
		unsigned long players, p1, p2, p3;
		double chalkPerM2, totalArea = 0;
		cin >> players >> chalkPerM2;
		for(unsigned long j = 0; j < players; ++j)
		{
			cin >> p1 >> p2 >> p3;
			// cout << p1 << p2 << p3 << endl;
			totalArea += area(p1, p2, p3);
		}
		// cout << totalArea << endl;
		// total area is in cm2 /10000*1000
		totalArea*=chalkPerM2/10.0;
		printf("%d\n", (unsigned long)round(totalArea));
	}


	return 0;
}
