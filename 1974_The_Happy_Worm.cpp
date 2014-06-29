#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

typedef std::pair<long, long> Stone;
typedef std::vector<Stone> Stones;

long free_spaces(long m, long n, const Stone &prev_stone, const Stone &current_stone) {
	return prev_stone.first != current_stone.first ?
	current_stone.first - prev_stone.first - 1
	+ (prev_stone.second <= n-2 ? 1 : 0)
	+ (current_stone.second >= 3 ? 1 : 0)
	:
	prev_stone.second + 2 < current_stone.second ? 1 : 0;
}

long long total_free_space(long m, long n, const Stones &stones) {
	long long result = 0;
	Stone first_stone(1,0);
	const Stone *prev_it = &first_stone;
	for (Stones::const_iterator it = stones.begin(); it != stones.end(); ++it) {
		result += free_spaces(m, n, *prev_it, *it);
		prev_it = &(*it);
	}
	Stone last_stone(m, n+1);
	result += free_spaces(m, n, *prev_it, last_stone);
	return result;
}

int main() {
	int t;
	scanf(" %d", &t);
	while (t--) {
		long m,n,k;
		scanf(" %ld %ld %ld", &m, &n, &k);
		Stones stones(k);
		while (k--)
			scanf(" %ld %ld", &stones[k].first, &stones[k].second);

		long long result = 0;
		sort(stones.begin(), stones.end());
		result += total_free_space(m, n, stones);

		for (long i=0; i<stones.size(); ++i)
			std::swap(stones[i].first, stones[i].second);
		sort(stones.begin(), stones.end());
		result += total_free_space(n, m, stones);

		printf("%lld\n", result);
	}
}
