#include <iostream>
#include <cmath>
#include <cstdio>

inline int calc_n (long x) {
	x *= 2;
	int n = ceil(sqrt((double)x));
	while (n * (n+1) >= x) n--;
	return n+1;
}

int main() {
	long x;
	while (std::cin >> x) {
		const int n = calc_n(x);
		const int offset = (int)(n*((long)n+1)/2-x);
		int up,down;
		if (n % 2) {
			up = offset+1;
			down = n - offset;
		}
		else {
			up = n - offset;
			down = offset+1;
		}
		printf("TERM %ld IS %d/%d\n", x, up, down);
	}
}
