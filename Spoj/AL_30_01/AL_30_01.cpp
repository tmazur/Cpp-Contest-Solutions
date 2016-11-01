#include <iostream>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <sstream>
#include <vector>
#include <stdio.h>
using namespace std;

void countCharFreq(char* str, unsigned long* freq) {
	int slen = strlen(str);
	for(unsigned long j = 0; j < slen; ++j) {
		++freq[str[j]-'a'];
	}

	// cout << "Nonzero charFreq for " << str << ": ";
	// for(int i = 0; i < 26; ++i) {
	// 	if(freq[i] > 0) cout << (char)(i+'a') << "=" << freq[i] << "; ";
	// }
	// cout << endl;
}

bool freqEqual(unsigned long* a, unsigned long* b) {
	for(int i = 0; i < 26; ++i) {
		if(a[i] != b[i]) return false;
	}
	return true;
}

int main()
{
	unsigned long freq[26] = {0};
	unsigned long baseFreq[26] = {0};
	ios_base::sync_with_stdio(false);
	char base[1001];
	char str[1001];
	cin >> base;
	countCharFreq(base, baseFreq);

	int num, anagrams = 0;
	cin >> num;
	for(unsigned long i = 0; i < num; ++i) {
		memset(freq, 0, sizeof(freq));
		cin >> str;

		countCharFreq(str, freq);
		if(freqEqual(freq, baseFreq)) {
			++anagrams;
		}
	}
	cout << anagrams;
	return 0;
}
