#include <iostream>
#include <cstring>
using namespace std;

const bool debug = false;
const int numberOfDays = 7;
const char* days[numberOfDays] = { "Pn", "Wt", "Sr", "Cz", "Pt", "So", "Nd" };

inline int getDay(char* dayInput)
{
	for(int i = 0; i < numberOfDays; ++i)
	{
		if(strcmp(dayInput, days[i]) == 0)
		{
			return i;
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	unsigned int tests;
  	cin >> tests;

  	char dayInput[3];
  	unsigned int dayOffset;
	char result[3];
	  for(int t = 0; t < tests; ++t)
	  {
	    cin >> dayInput;
	    cin >> dayOffset;

			unsigned int inputDayNum = getDay(dayInput);
			unsigned int resultNum = inputDayNum + (dayOffset % numberOfDays);
			resultNum %= numberOfDays;
			strcpy(result, days[resultNum]);
	    if(debug)
	    {
	      cout << "DayIn = " << dayInput << inputDayNum << " offset = " << dayOffset << " Result = " << result << resultNum << endl;
	    }
		cout << result << endl;
 	}
	return 0;
}
