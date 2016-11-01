#include <iostream>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <sstream>
#include <vector>
#include <stdio.h>
using namespace std;

const bool debug = false;
vector<unsigned long> connections[200001];
vector<unsigned long> routeToTarget[200001];
int main()
{
	ios_base::sync_with_stdio(false);
	unsigned long connectionsNum, queries;
	cin >> connectionsNum;

	for(unsigned long i = 0; i < connectionsNum - 1; ++i) {
		unsigned long a,b;
		cin >> a >> b;
		connections[a].push_back(b);
		connections[b].push_back(a);
	}

	vector<unsigned long> toVisit;
	routeToTarget[1].push_back(1);
	toVisit.push_back(1);
	while(toVisit.size() > 0) {
		unsigned long node = toVisit.back();
		toVisit.pop_back();

		for(auto x : connections[node]) {
			if(x != 1 && routeToTarget[x].size() == 0) {
				toVisit.push_back(x);
				routeToTarget[x].insert(routeToTarget[x].begin(), routeToTarget[node].begin(), routeToTarget[node].end());
				routeToTarget[x].push_back(x);
			}
		}
	}

	if(debug) {
		for(unsigned long i = 1; i <= connectionsNum; ++i) {
			cout << "Route from " << i << ": ";
			for(auto x : routeToTarget[i]) {
				cout << x << ", ";
			}
			cout << endl;
		}
	}


	cin >> queries;
	for(unsigned long i = 0; i < queries; ++i)
	{
		unsigned long a,b;
		cin >> a >> b;

		unsigned long minRoute = min(routeToTarget[a].size(), routeToTarget[b].size());
		unsigned long meetAt=0;
		unsigned long fineSearchStart = minRoute-1;

		while(routeToTarget[a][fineSearchStart] != routeToTarget[b][fineSearchStart]) {
			fineSearchStart /= 2;
			if(fineSearchStart < 20) {
				fineSearchStart = 0; // stop optimizing at this point
			}
		}
		fineSearchStart = guess;

		if(debug) cout << "fineSearchStart=" << fineSearchStart << endl;
		for(unsigned long j = fineSearchStart; j < minRoute; ++j) {
			if(routeToTarget[a][j] == routeToTarget[b][j]) {
				meetAt = routeToTarget[a][j];
			} else {
				j=minRoute;
			}
		}

		cout << meetAt << "\n";

	}
	return 0;
}
