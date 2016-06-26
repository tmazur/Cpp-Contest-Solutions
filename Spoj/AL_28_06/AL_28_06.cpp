#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

const bool debug = false;
double enemyEvasion[1000];
double evadeChance;

int main() {
	ios_base::sync_with_stdio(false);
	unsigned int tests;
	cin >> tests;

	for(unsigned int t = 0; t < tests; ++t)
	{
		unsigned long n;
		cin >> n;
		cin >> evadeChance;

		for(int i = 0; i < n; ++i) {
			cin >> enemyEvasion[i];
		}

		double expectedDamage = 0.0f;
		for(int i = 0; i < n; ++i) {
			expectedDamage += (1.0f - evadeChance) / (1.0f - enemyEvasion[i]);
		}

		printf("%.6f\n", expectedDamage);
		// cout << std::setprecision(6) << std::fixed << expectedDamage << "\n";
	}
	return 0;
}
