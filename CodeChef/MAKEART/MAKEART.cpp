#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const bool debug = false;

const int brushSize = 3;
unsigned int target[100000];
unsigned int current[100000];

inline bool verify(unsigned int N) {
	for(unsigned int i = 0; i < N; ++i) {
		if(target[i] != current[i]) {
			if(debug) cout << "Verify failed on " << i << " expected " << target[i] << " got " << current[i] << " N=" << N << endl;
			return false;
		}
	}
	return true;
}

inline void paintForwards(unsigned int start, const unsigned int color) {
	if(debug) cout << "FrontPaint " << start << "-" << start+brushSize-1 << " with " << color << endl;
	current[start] = color;
	current[start+1] = color;
	current[start+2] = color;
}

inline void paintBackwards(unsigned int start, const unsigned int color) {
	if(debug) cout << "BackPaint " << start-brushSize+1 << "-" << start << " with " << color << endl;
	current[start] = color;
	current[start-1] = color;
	current[start-2] = color;
}

int main() {
	ios_base::sync_with_stdio(false);
	unsigned int tests;
	cin >> tests;
	for(unsigned int i = 0; i < tests; ++i) {
		unsigned int N;
		cin >> N;
		// memset(current, 0, sizeof(current));
		for(unsigned int j = 0; j < N; ++j) {
			cin >> target[j];
		}

		bool possible = true;
		for(unsigned int j = 0; j <= N-brushSize; ++j) {
			unsigned int color = target[j];
			if(current[j] != color) {
				paintForwards(j, color);
			}
		}
		current[N-2] = 0;
		current[N-1] = 0;
		// everything is painted correctly besides the last two spots...
		unsigned int verifyDownTo = N-2;
		for(unsigned int j = N-1; j >= verifyDownTo && j < N; --j) {
			unsigned int color = target[j];
			if(debug) cout << "Back test " << j << " curr = " << current[j] << " target = " << target[j] << endl;
			if(current[j] != target[j]) {
				if(j < 2) {
					if(debug) cout << "Not possible to BackPaint on " << j << "!" << endl;
					verifyDownTo = j; // exit loop
					possible = false;
					break;
				}
				paintBackwards(j, color);
				if(debug) cout << "verifyDownTo= " << j-2 << endl;
				verifyDownTo = min(verifyDownTo, j-2);
			}
		}

		if(possible) printf("Yes\n"); else printf("No\n");
	}

	return 0;
}
