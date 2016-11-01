#include <iostream>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <sstream>
#include <vector>
#include <stdio.h>
using namespace std;

unsigned long piles[1000000];
unsigned long num;
unsigned long fullNimsum=0;

unsigned long getNimSum(unsigned long numPile, unsigned long toRemove) {
	return fullNimsum ^ piles[numPile] ^ (piles[numPile] - toRemove);
}

void findWinningMove() {
	for(unsigned long i = 0; i < num; ++i) {
		for(unsigned long j = 1; j <= piles[i]; ++j) {
			if(getNimSum(i, j) == 0) {
				cout << (i+1) << " " << j << "\n";
				return;
			}
		}
	}
	cout << "0 0\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> num;

	for(unsigned long i = 0; i < num; ++i) {
		cin >> piles[i];
		fullNimsum ^= piles[i];
	}

	// cout << "fullNimsum=" << fullNimsum << endl;
	if(fullNimsum == 0) {
		cout << "0 0\n";
	} else {
		findWinningMove();
	}


	return 0;
}
