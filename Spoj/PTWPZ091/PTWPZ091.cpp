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

	unsigned long num;
	for(unsigned long t = 0; t < tests; ++t)
	{
		fastIoInt<unsigned long>(&num);
		long maxH = 0, maxX = 0, maxY = 0, minY = 0, minX = 0;
		for(unsigned long i = 0; i < num; ++i)
		{
			long x,y,h,r;
			fastIoInt<long>(&x);
			fastIoInt<long>(&y);
			fastIoInt<long>(&h);
			fastIoInt<long>(&r);
			maxH = max(maxH, h+r);
			if(i==0)
			{
				maxX = x+r;
				minX = x-r;
				minY = y-r;
				maxY = y+r;
			}
			else
			{
				maxX = max(maxX, x+r);
				minX = min(minX, x-r);
				maxY = max(maxY, y+r);
				minY = min(minY, y-r);
			}
		}

		long spanX = maxX - minX;
		long spanY = maxY - minY;
		// cout << spanX << ", " << spanY << ", " << maxH << endl;
		printf("%d\n", spanX*spanY + 2*spanX*maxH + 2*spanY*maxH);
	}
	return 0;
}
