#include <iostream>
#include <queue>
#include <stdint.h>
using namespace std;

std::queue<unsigned int> bestRunners;
char names[100000][2][21];

const bool debug = false;

// print runner with best time. for ties print runners in order as they appeared
int main() {
	ios_base::sync_with_stdio(false);
	unsigned int tests;
	scanf("%d", &tests);

	unsigned int bestTimeInSeconds = INT32_MAX;
	for(int t = 0; t < tests; ++t)
	{
		unsigned int min, sec;
		scanf("%s %s %d:%d", names[t][0] , names[t][1], &min, &sec);
		unsigned int convertedToSeconds = min*60 + sec;
		if(convertedToSeconds < bestTimeInSeconds)
		{
			// clear the queue
			while(!bestRunners.empty())
			{
				bestRunners.pop();
			}
			bestTimeInSeconds = convertedToSeconds;
			bestRunners.push(t); // add runner-id to queue
		}
		else if (convertedToSeconds == bestTimeInSeconds)
		{
			bestRunners.push(t);
		}
		if(debug)
		{
			cout << names[t][0] << " " << names[t][1] << " time in secs = " << min*60+sec << endl;
		}
	}
	while(!bestRunners.empty())
	{
		unsigned int runner = bestRunners.front();
		bestRunners.pop();
		cout << names[runner][0] << " " << names[runner][1] << endl;
	}
	return 0;
}
