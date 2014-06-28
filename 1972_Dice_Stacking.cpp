#include <iostream>
#include <algorithm>
#include <cstdio>

const unsigned opposite_sides[6] = {
	5, 3, 4, 1, 2, 0
};

unsigned adjacent_sides[6][4];


unsigned max_of_adjacent_sides(unsigned side, unsigned *dice){
	unsigned result = 0;
	for (unsigned i=0; i<4; ++i)
		result = std::max(result, dice[adjacent_sides[side][i]]);
	return result;
}


int main() {

	for (unsigned i =0; i<6; ++i) {
		unsigned k=0;
		for (unsigned j=0; j<6; ++j)
			if (j != i && opposite_sides[j] != i)
				adjacent_sides[i][k++] = j;
	}

	unsigned t;
	std::cin >> t;
	while (t--) {
		unsigned n;
		std::cin >> n;
		unsigned maxes1[7] = {0};
		unsigned maxes2[7];
		unsigned *previous_maxes = maxes1;
		unsigned *current_maxes = maxes2;
		while (n--) {
			unsigned dice[6];
			for (unsigned i = 0; i<6; ++i)
				std::cin >> dice[i];
			for (unsigned i=0; i<6; ++i)
				current_maxes[dice[opposite_sides[i]]] = previous_maxes[dice[i]] + max_of_adjacent_sides(i, dice);
			std::swap(previous_maxes, current_maxes);
		}
		unsigned answer = 0;
		for (unsigned i=1; i<=6; ++i)
			answer = std::max(answer, previous_maxes[i]);
		printf("%d\n", answer);
	}
}
