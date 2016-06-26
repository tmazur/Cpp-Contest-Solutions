#include <iostream>
#include <cstdlib>
using namespace std;

const bool debug = false;

unsigned long long int calc(unsigned long long num1, unsigned long long servingTime1, unsigned long long num2, unsigned long long servingTime2, unsigned long long num3, unsigned long long servingTime3)
{
	unsigned long long servingTime = (num1+1) * servingTime1;

	unsigned long long flushQueue2 = num2*servingTime2;
	if(servingTime >= flushQueue2) {
		servingTime += servingTime2;
	} else {
		servingTime = servingTime2 + flushQueue2;
	}

	unsigned long long flushQueue3 = num3*servingTime3;
	if(servingTime >= flushQueue3) {
		servingTime += servingTime3;
	} else {
		servingTime = servingTime3 + flushQueue3;
	}

	return servingTime;
}

int main() {
	ios_base::sync_with_stdio(false);
	unsigned long tests;
	cin >> tests;

	for(unsigned long t = 0; t < tests; ++t)
	{
		unsigned long long A, B, C, a, b, c;
		cin >> A >> B >> C >> a >> b >> c;

		unsigned long long int r1 = calc(A, a, B, b, C, c);
		r1 = min(r1, calc(A, a, C, c, B, b));
		r1 = min(r1, calc(C, c, A, a, B, b));
		r1 = min(r1, calc(C, c, B, b, A, a));
		r1 = min(r1, calc(B, b, A, a, C, c));
		r1 = min(r1, calc(B, b, C, c, A, a));

		cout << r1 << "\n";
	}
	return 0;
}
