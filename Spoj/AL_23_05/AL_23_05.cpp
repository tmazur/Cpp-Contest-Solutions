#include <iostream>
using namespace std;

int span;

unsigned long pathFind(unsigned long *map, int posX, int posY) {
	unsigned long paths = 0;
	if(posX == span-1 && posY == span-1) {
		// cout << "reached end" << posX << "," << posY;
		return 1;
	}
	if(posY+1 < span) {
		if(*(map+span*posX+(posY+1)) == 1) {
			*(map+span*posX+(posY+1)) = pathFind(map, posX, posY+1);
		}
		paths += *(map+span*posX+(posY+1));
	}
	if(posX+1 < span) {
		if(*(map+span*(posX+1)+(posY)) == 1) {
			*(map+span*(posX+1)+(posY)) = pathFind(map, posX+1, posY);
		}
		paths += *(map+span*(posX+1)+(posY));
	}
	// if(paths>1)
	// 	cout << paths << endl;
	return paths % 1000000009;
}

int main() {
	ios_base::sync_with_stdio(false);
	
	int tests;
	char tmp;
  	cin >> tests;
  	for(int i = 0; i < tests; i++) {
  		cin >> span;
  		unsigned long *map = new unsigned long[span*span]; // true==.free space
  		for(int x = 0; x < span; x++) {
  			for(int y = 0; y < span; y++) {
	  			cin >> tmp;
	  			*(map+x*span+y) = (tmp == '.');
  			}
  		}
  		// map read
  		// navigate from TL to BR
  		unsigned long paths = pathFind(map, 0, 0);
  		cout << paths;
  		if( i+1 < tests) cout << "\n";
  		delete[] map;
  	}
	return 0;
}