#include <iostream>
using namespace std;

bool isPrime(unsigned int n)
{
    if(n <= 1) {
        return false;
    }
    else if (n <= 3) {
        return true;
    }
    else if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }

    for(unsigned int i = 5; i*i <= n; i=i+6) {
        if(n % i == 0 || n % (i+2) == 0)
            return false;
    }
    return true;
}

int main() {
	ios_base::sync_with_stdio(false);

	int tests;
  cin >> tests;
	for(int i = 0; i < tests; i++) {
    unsigned int start, end;
    cin >> start;
    cin >> end;

    // if(start == 2)
    //     cout << 2 << endl;
    //
    //
    // if(start % 2 == 0)
    //     ++start; // start with an odd

    for(unsigned int j = start; j <= end; ++j) {
        if(isPrime(j)) {
            cout << j << endl;
        }
    }

    // cout << "Start " << start << " to end " << end;
    cout << endl;
	}
	return 0;
}
