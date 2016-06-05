#include <iostream>
using namespace std;
const bool debug = false;

unsigned int timeUp[10000];

int main() {
	ios_base::sync_with_stdio(false);
	unsigned int tests;
	cin >> tests;
	for(int i = 0; i < tests; ++i) {
		unsigned int finishedCookingCounter = 0;
		unsigned int startTime = 0;
		unsigned int users;
		cin >> users;
		for(int j = 0; j < users; ++j) {
			cin >> timeUp[j];
		}
		unsigned int timeNeed;
		for(int j = 0; j < users; ++j) {
			cin >> timeNeed;
			if(j == 0) {
				if(timeNeed <= timeUp[j]) {
					++finishedCookingCounter;
				}
			} else {
				if(timeUp[j-1] + timeNeed <= timeUp[j]) {
					++finishedCookingCounter;
				}
			}
		}
		cout << finishedCookingCounter << '\n';
	}

	return 0;
}
