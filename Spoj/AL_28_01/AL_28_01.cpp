#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

const int maxLength = 29;
char output[maxLength+1] = ".............................";
const bool debug = false;

int main() {
	ios_base::sync_with_stdio(false);
	unsigned int length;
	cin >> length;

	output[length] = 0;
	char text[maxLength];
	cin >> text;

	const int start = length / 2;
	if(debug) cout << "start = " << start << endl;
	output[start] = text[start];

	for(int i = 0; start+i < length; ++i)
	{
		output[start+i] = text[start+i];
		output[start-i] = text[start-i];
		cout << output << "\n";
	}
	
	return 0;
}
