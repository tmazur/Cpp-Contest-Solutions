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

struct Range {
	unsigned long long start;
	unsigned long long end;

	inline unsigned long long length()
	{
		return end - start;
	}

	inline bool overlaps(const Range a)
	{
		return !(end <= a.start || a.end <= start);
	}

	/**
	* sort by ascending endTime, if equal then by ascending startTime
	**/
	inline bool operator<(const Range & a) {
		if(end < a.end)
			return true;
		if(end > a.end)
			return false;
		return start < a.start;
	}
};

const int MAX_NUM = 100000;
Range ranges[MAX_NUM] = {};
unsigned long long opt[MAX_NUM+1] = {};

inline long findBestFittingPreviousClip(unsigned long i)
{
	long long start = ranges[i].start;
	long up = i-1, low = 0;
	while(up - low > 1)
	{
		long step = (up-low)/2;
		if(ranges[low+step].end <= start)
		{
			// lower bound still meets condition
			low += step;
		}
		else if (!(ranges[up-step].end <= start))
		{
			// upper bound still fails to meet condition
			up -= step;
		}
	}
	// now the solution is low, up, or neither
	if(!(ranges[low].end <= start))
	{
		return -1; // no clip fits before
	}
	else if (ranges[up].end <= start)
	{
		return up;
	}
	return low;
}

int main() {
	ios_base::sync_with_stdio(false);
	unsigned long tests;
	// cin >> tests;
	fastIoInt<unsigned long>(&tests);

	unsigned long num;
	for(unsigned long t = 0; t < tests; ++t)
	{
		fastIoInt<unsigned long>(&num);
		// cin >> num;
		for(unsigned long i = 0; i < num; ++i)
		{
			// cin >> ranges[i].start >> ranges[i].end;
			fastIoInt<unsigned long long>(&ranges[i].start);
			fastIoInt<unsigned long long>(&ranges[i].end);
		}
		memset(opt, 0, sizeof(opt));
		std::sort(ranges, ranges + num);

		opt[0] = 0;
		for(unsigned long i = 1; i <= num; ++i)
		{
			long idxBestFitBeforeI = findBestFittingPreviousClip(i-1);
			if(idxBestFitBeforeI <= -1)
			{
				if(debug)
				{
					cout << "no range with endTime <= " << ranges[i-1].start <<
						"; opt[i=" << i << "]=max(" << ranges[i-1].length() << "; " << opt[i-1] << ")" << endl;
				}
				opt[i] = max(ranges[i-1].length(), opt[i-1]);
			}
			else
			{
				if(debug)
				{
					cout << "idxBestFitBeforeI=" << idxBestFitBeforeI << ";      " << ranges[idxBestFitBeforeI].start << ", " << ranges[idxBestFitBeforeI].end << " should have end <= " << ranges[i-1].start << endl;
					cout << "opt[i=" << i << "]=max(" << opt[idxBestFitBeforeI] << " + " << ranges[i-1].length() << "; " << opt[i-1] << ")" << endl;
				}
				opt[i] = max(opt[idxBestFitBeforeI+1] + ranges[i-1].length(), opt[i-1]);
			}
		}
		// cout << opt[num] << '\n';
		printf("%d\n", opt[num]);
	}
	return 0;
}
