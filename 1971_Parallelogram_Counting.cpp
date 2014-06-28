#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

typedef std::pair<long, long> Line;
typedef Line Point;


struct LineEntry {
	Line line;
	double character_value;
	int p_index;
};

bool operator<(const LineEntry &e1, const LineEntry &e2) {
	return
		e1.line != e2.line ? e1.line < e2.line
	: e1.character_value < e2.character_value;
}


std::vector<LineEntry> lines;
std::vector<Point> points;


Line operator-(const Point &a, const Point &b) {
	Line result;
	result.first = a.first - b.first;
	result.second = a.second - b.second;
	return result;
}

void negate(Line &line) {
	line.first = -line.first;
	line.second = -line.second;
}

inline long combination2(long n) {
	return n*(n-1)/2;
}


double character_value(const Point &p, const Line &l) {
	if (l.first != 0)
		return p.second - p.first * (double) l.second / l.first;
	else
		return l.second;
}

bool in_different_line(const Point &p1, const Point &p2, const Line &l) {
	return (long long) (p1.first - p2.first) * l.second
	- (long long) (p1.second - p2.second) * l.first;
}


inline long combination2(long doubles, long singles) {
	return 2 * 2 * combination2(doubles)
	+ 2 * doubles * singles
	+ combination2(singles);
}


int main() {
	int t;
	std::cin >> t;
	while (t--) {
		int n;
		std::cin >> n;
		points.resize(n);
		for (int i=0; i<n; ++i)
			std::cin >> points[i].first >> points[i].second;
		lines.resize(combination2(n));
		long k = 0;
		for (int i=0; i<n; ++i)
			for (int j=i+1; j<n; ++j) {
				Line offset = points[i] - points[j];
				if (offset.first < 0 || (offset.first ==0 && offset.second < 0)) negate(offset);
				lines[k].line = offset;
				lines[k].character_value = character_value(points[i], offset);
				lines[k++].p_index = i;
			}
		sort(lines.begin(), lines.end());
		long i=0;
		k=0;
		long total = 0;
		long doubles=0, singles=1;
		for (long j=1; j<lines.size(); ++j) {
			if (lines[i].line != lines[j].line) {
				total += combination2(doubles, singles);
				i=k=j;
				doubles = 0;
				singles = 1;
			}
			else if (!in_different_line(points[lines[k].p_index], points[lines[j].p_index], lines[k].line)) {
				singles--;
				doubles++;
			}
			else {
				k=j;
				singles++;
			}
		}
		total += combination2(doubles, singles);
		printf("%ld\n", total/2);
	}

}
