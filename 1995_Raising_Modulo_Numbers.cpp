#include <cstdio>
#include <climits>
#include <iostream>

const int long_bits = CHAR_BIT * sizeof(unsigned long);

unsigned M;

unsigned power2(unsigned rem) {
	return (unsigned long) rem * rem % M;
}

long atob(unsigned long a, unsigned long b) {
	unsigned result = 1;
	unsigned rem_a = a % M;
	for (unsigned long bit = (unsigned long) 1 << (long_bits-1); bit > 0; bit >>= 1)
		result = (unsigned)((unsigned long) power2(result) * (bit & b ? rem_a : 1) % M);
	return result;
}

int main() {
	unsigned Z;
	std::cin >> Z;
	while (Z--) {
		std::cin >> M;
		unsigned H;
		std::cin >> H;
		unsigned total = 0;
		while (H--) {
			unsigned long a,b;
			std::cin >> a >> b;
			total = ((unsigned long) total + atob(a,b)) % M;
		}
		printf("%d\n", total);
	}
}
