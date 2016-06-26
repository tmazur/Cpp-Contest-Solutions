#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

const bool debug = false;
char field[100][100];

inline bool isField(int startX, int startY, int size) {
	bool isField = true;
	for(int i = 0; i < size && isField; ++i) {
		isField &= field[startX+size-1][startY+i] == '.';
		isField &= field[startX+i][startY+size-1] == '.';
		if(debug) cout << "isField start("<< startX << "," << startY << ") size(" << size << ")" << startX+size-1 << "," << startY+i << "  " << startX+i << "," << startY+size-1 << endl;
	}
	return isField;
}

int main() {
	ios_base::sync_with_stdio(false);
	unsigned int tests;
	cin >> tests;

	for(unsigned int t = 0; t < tests; ++t)
	{
		unsigned long n;
		cin >> n;

		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				cin >> field[i][j];
			}
		}

		int largestSquare = 0;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				if(field[i][j] == '.') {
					int size = 1;
					while(i + size < n && isField(i, j, size+1)) {
						++size;
						if(debug) cout << "found square: " << i << ", " << j << " with size " << size << endl;
					}
					largestSquare = max(largestSquare, size*size);
				}
			}
		}


		cout << largestSquare << "\n";
	}
	return 0;
}
