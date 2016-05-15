#include <iostream>
#include <cstring>
using namespace std;

const bool debug = false;
const std::pair<int, int> categories[3] = {{'A', 'Z'}, {'a', 'z'}, {'0', '9'}};
const int targetStrength = 0x0F;
const int requiredPasswordLength = 8;

// print passwords that are 'strong'
// a strong password has:
// - at least 8 chars
// - chars from each of the three defined categories
// - chars that do not fit into any of the defined categories
int main() {
	ios_base::sync_with_stdio(false);
	unsigned int tests;
	cin >> tests;

	cin.ignore (1, '\n');
	for(int t = 0; t < tests; ++t)
	{
		char password[1001];
		int passwordStrength = 0, i = 0;
		cin.getline(password,sizeof(password));
		if(debug) cout << t << ":" << password << endl;
		do
		{
			// loop through all chars, or until passwordStrength mets target
			bool belongsToKnownCategory = false;
			for(int j = 0; j < 3; ++j)
			{
				if(password[i] >= categories[j].first && password[i] <= categories[j].second)
				{
					passwordStrength |= (1 << j);
					belongsToKnownCategory = true;
					break;
				}
			}
			if(!belongsToKnownCategory)
			{
				passwordStrength |= (1 << 3);
			}
		} while(password[++i] != 0 && passwordStrength != targetStrength);

		if(debug)
		{
			cout << password << " passwordStrength=" << passwordStrength << "len=" << strlen(password) << endl;
		}
		if(passwordStrength == targetStrength && strlen(password) >= requiredPasswordLength)
		{
			cout << password << endl;
		}
	}
	return 0;
}
