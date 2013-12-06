#include <iostream>

int u;
int distance_from_center(int i) {
	return abs(i-u);
}

int main() {
	int N;
	std::cin >> N;
	for (int scenario=1; scenario<=N; ++scenario) {
		if (scenario > 1)
			puts("");
		printf("Scenario #%d:\n", scenario);

		std::cin >> u;

		const int edge_size = 2*u+1;

		for (int k=0; k<edge_size; ++k) {
			printf("slice #%d:\n", k+1);
			for (int i=0; i<edge_size; ++i) {
				for (int j=0; j<edge_size; ++j) {
					const int distance =
						distance_from_center(i)
						+ distance_from_center(j)
						+ distance_from_center(k);
					putchar(distance > u ? '.' : '0' + distance);
				}
				putchar('\n');
			}
		}
	}
}
