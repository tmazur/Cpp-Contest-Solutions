#include <iostream>
#include <string>
using namespace std;
const bool debug = false;

string getPalindrome(int n) {
	string r;
	for(int i = 0; i < n; ++i) {
		r += (char)('a' + (i%26));
	}
	return r;
}

int main() {
	ios_base::sync_with_stdio(false);
	unsigned int tests;
	cin >> tests;
	for(int i = 0; i < tests; ++i) {
		unsigned int N;
		cin >> N;
		cout << getPalindrome(N) << '\n';
	}

	return 0;
}
