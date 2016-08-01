#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

const bool debug = false;

inline unsigned long long getPiecesForNCuts(unsigned long long n)
{
	return (n*n+n+2)/2;
}

unsigned long long getMinCutsForNGuests(unsigned long long guests)
{
	if(guests == 1) return 0; // they want to trick us!
	unsigned long long cuts = std::sqrt((double)guests); // we'll need at least this many cuts
	unsigned long long pieces = getPiecesForNCuts(cuts);
	if(debug) cout << "Initially for " << cuts << " cuts we get " << pieces << " pieces" << endl;
	while(pieces < guests)
	{
		++cuts;
		pieces += cuts;

	}
	if(debug) cout << "To serve " << guests << " guests we need " << cuts << " cuts" << endl;
	return cuts;
}

int main() {
	ios_base::sync_with_stdio(false);
	{
		unsigned long long guests;
		while(cin >> guests)
		{
			cout << getMinCutsForNGuests(guests) << "\n";
		}
	}
	return 0;
}
