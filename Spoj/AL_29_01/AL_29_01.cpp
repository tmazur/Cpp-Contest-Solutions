#include <iostream>
#include <cstdlib>
#include <cstring>
#include <stdio.h>
using namespace std;

const bool debug = false;

template<typename T>
inline bool ioInt(T *a)
{
    register char c=0;
    while (c<33 && c != EOF) c=getchar_unlocked();
	if(c==EOF)
		return false;
    *a=0;
    while (c > 47 && c < 58)
    {
        *a=*a*10+c-'0';
        c=getchar();
    }
	return true;
}

inline unsigned long readInHmsToS()
{
	unsigned long temp, timeInS = 0;
	ioInt<unsigned long>(&temp);
	timeInS += temp * 60 * 60;
	// if(debug) cout << "Time=" << temp;
	ioInt<unsigned long>(&temp);
	timeInS += temp * 60;
	// if(debug) cout << ":" << temp;
	ioInt<unsigned long>(&temp);
	timeInS += temp;
	// if(debug) cout << ":" << temp << endl;
	return timeInS;
}

int main() {
	ios_base::sync_with_stdio(false);
	unsigned long tests;
	// cin >> tests;
	ioInt<unsigned long>(&tests);

	unsigned long numNegativeSplit = 0, numNegativeSplitMetTarget = 0, numOther = 0, numOtherMetTarget = 0;
	for(unsigned long t = 0; t < tests; ++t)
	{
		unsigned long t5 = readInHmsToS();
		unsigned long t10 = readInHmsToS();
		unsigned long t15 = readInHmsToS();
		unsigned long t20 = readInHmsToS();
		unsigned long tTotal = readInHmsToS();
		unsigned long tTarget = readInHmsToS();

		// if(debug) cout << "TimeInS: " << t5 << ", " << t10 << ", " << t15 << ", " << t20 << endl;
		// unsigned long dt1 = t5, dt2 = t10 - t5, dt3 = t15 - t10, dt4 = t20 - t15;
		// if(debug) cout << "DeltaT: " << dt1 << ", " << dt2 << ", " << dt3 << ", " << dt4 << endl;

		bool negativeSplit =  (t10 - t5 <= t5 && t15 - t10 <= t10 - t5 && t20 - t15 <= t15 - t10 && t5 > t20 - t15);
		bool metTarget = tTotal <= tTarget;
		if(negativeSplit)
		{
			++numNegativeSplit;
			if(metTarget) ++numNegativeSplitMetTarget;
		}
		else
		{
			++numOther;
			if(metTarget) ++numOtherMetTarget;
		}
	}
	printf("%d/%d %d/%d", numNegativeSplitMetTarget, numNegativeSplit, numOtherMetTarget, numOther);
	return 0;
}
