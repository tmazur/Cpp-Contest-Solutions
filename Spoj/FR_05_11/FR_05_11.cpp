#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

const bool debug = false;
int heights[1000];
bool heightsUsed[1000];

int main() {
	ios_base::sync_with_stdio(false);
	unsigned int tests;
	cin >> tests;

	for(unsigned int t = 0; t < tests; ++t)
	{
		unsigned int num;
		cin >> num;
		memset(heightsUsed, 0, num * sizeof(bool));
		for(unsigned int i = 0; i < num; ++i)
		{
			cin >> heights[i];
		}
		// sort the heights
		qsort(heights, num, sizeof(unsigned int), [](const void* a, const void* b)
		{
			int arg1 = *static_cast<const int*>(a);
			int arg2 = *static_cast<const int*>(b);

			if(arg1 < arg2) return -1;
			if(arg1 > arg2) return 1;
			return 0;
		});
		if(debug)
		{
			for(unsigned int i = 0; i < num; ++i)
			{
				cout << heights[i] << " ";
			}
			cout << endl;
		}

		int numsLeft = num;
		int lastHop = -1;
		int i = 0, hopsCounter = 0;
		while(numsLeft > 0)
		{
			if(debug) {cout << "iter:" << i << " numsLeft:" << numsLeft << " h:" << heights[i] << " lastHeight:" << lastHop << endl;}
			if(!heightsUsed[i] && heights[i] > lastHop)
			{
				if(lastHop != -1)
				{
					++hopsCounter;
				}
				if(debug)
				{
					if(lastHop != -1)
					{
						cout << "Hop onto height " << heights[i] << endl;
					}
					else
					{
						cout << "Start with height " << heights[i] << endl;
					}
				}

				lastHop = heights[i];
				heightsUsed[i] = true;
				--numsLeft;
			}

			++i;
			if(i >= num)
			{
				i = 0;
				lastHop = -1;
			}
		}
		cout << hopsCounter << endl;
	}
	return 0;
}
