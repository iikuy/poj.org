#include <cstdio>
#include <vector>

typedef std::vector<std::vector<int> > Graph;

int calc_rank(int i, const Graph &g, std::vector<int> &ranks, std::vector<bool> &visited) {
	if (visited[i]) return ranks[i];
	visited[i] = true;
	ranks[i] = 1;
	for (int j=0; j<g[i].size(); ++j)
		ranks[i] += calc_rank(g[i][j], g, ranks, visited);
	return ranks[i];
}

void calc_rank(int N, const Graph &g, std::vector<int> &ranks) {
	std::vector<bool> visited(N+1);
	for (int i=1; i<g.size(); ++i)
		calc_rank(i, g, ranks, visited);
}

int main() {
	int t;
	scanf(" %d", &t);
	while (t--) {
		int N, M;
		scanf(" %d %d", &N, &M);
		Graph g1(N+1), g2(N+1);
		while (M--) {
			int n1,n2;
			scanf(" %d %d", &n1, &n2);
			g1[n1].push_back(n2);
			g2[n2].push_back(n1);
		}

		const int mid = (N+1)/2;
		std::vector<int> rank1(N+1), rank2(N+1);
		calc_rank(N, g1, rank1);
		calc_rank(N, g2, rank2);

		int result = 0;
		for (int i=1; i<N+1; ++i)
			if (rank1[i] > mid || rank2[i]>mid) result++;

		printf("%d\n", result);
	}

}
