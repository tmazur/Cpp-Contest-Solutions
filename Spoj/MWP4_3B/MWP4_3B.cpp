#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const bool debug = false;
const unsigned long START_TIME = 9*60*60;
const unsigned long END_TIME = 14*60*60;

template<typename T>
inline bool fastIoInt(T *a)
{
    register char c=0;
    while (c<33 && c != EOF) c=getchar_unlocked();
	if(c==EOF)
		return false;
    *a=0;
    while (c > 47 && c < 58)
    {
        *a=*a*10+c-'0';
        c=getchar_unlocked();
    }
	return true;
}

inline bool isAcOnInput()
{
    register char c=0;
    while (c<33 && c != EOF) c=getchar_unlocked();
	if(c==EOF)
		return false;

	bool isAC = false;
	if(c=='A')
	{
		if(getchar_unlocked() == 'C')
		{
			isAC = true;
		}
	}
	c=getchar_unlocked();
	while(c != '\n' && c != EOF) { c=getchar_unlocked(); }
	return isAC;
}

inline unsigned long readInHmsToS()
{
	unsigned long temp, timeInS = 0;
	fastIoInt<unsigned long>(&temp);
	timeInS += temp * 60 * 60;
	// if(debug) cout << "Time=" << temp;
	fastIoInt<unsigned long>(&temp);
	timeInS += temp * 60;
	// if(debug) cout << ":" << temp;
	fastIoInt<unsigned long>(&temp);
	timeInS += temp;
	// if(debug) cout << ":" << temp << endl;
	return timeInS;
}

int main() {
	ios_base::sync_with_stdio(false);
	unsigned long tests;
	fastIoInt<unsigned long>(&tests);

	for(unsigned long t = 0; t < tests; ++t)
	{
		unsigned long num;
		fastIoInt<unsigned long>(&num);
		unsigned long sleepDelayInS = readInHmsToS();

		unsigned long longestSleepTime = 0, lastTimeAwakeS = START_TIME, curTimeS;
		for(unsigned long j = 0; j < num; ++j)
		{
			curTimeS = readInHmsToS();
			if(isAcOnInput())
			{
				unsigned long diff = curTimeS - lastTimeAwakeS;
				// if(debug) cout << "AC at " << curTimeS << " with diff from lastAwake " << diff << endl;
				if(diff > sleepDelayInS)
				{
					longestSleepTime = max(longestSleepTime, diff-sleepDelayInS);
				}

				lastTimeAwakeS = curTimeS;
			}
		}
		unsigned long lastAcToEndTime = END_TIME - lastTimeAwakeS;
		if(lastAcToEndTime > sleepDelayInS)
			longestSleepTime = max(longestSleepTime, lastAcToEndTime - sleepDelayInS);

		if(longestSleepTime > 0)
		{
			unsigned long h = longestSleepTime/60/60;
			unsigned long m = longestSleepTime/60 - h*60;
			unsigned long s = longestSleepTime % 60;
			printf("%02d:%02d:%02d\n", h, m, s);
		}
		else
		{
			printf("0\n");
		}



	}
	return 0;
}
