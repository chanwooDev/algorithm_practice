#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;

const double Pi = 2 * acos(0);
const int inf = 987654321;
int n;
double y[100], x[100], r[100];
pair<double, double>ranges[100];
void convertToRange()
{
	for (int i = 0; i < n; ++i)
	{
		double loc = fmod(2 * Pi + atan2(y[i], x[i]), 2 * Pi);
		double range = 2 * asin(r[i] / 16);
		ranges[i] = { loc - range,loc + range };
	}

	sort(ranges, ranges + n);
}
int linear(double lo, double hi)
{
	int used = 0, idx = 0;
	while (lo < hi)
	{
		double maxCover = -1;
		while (idx < n && ranges[idx].first <= lo)

			maxCover = max(maxCover, ranges[idx++].second);

		if (maxCover <= lo) return inf;

		lo = maxCover;
		++used;
	}
	return used;
}
int solve()
{
	int ret = inf;

	for (int i = 0; i < n; ++i)
		if (ranges[i].first <= 0 || ranges[i].second >= 2 * Pi)
		{
			double lo = fmod(ranges[i].second, 2 * Pi);
			double hi = fmod(ranges[i].first + 2 * Pi, 2 * Pi);
			ret = min(ret, 1 + linear(lo, hi));
		}

	return ret;
}
int main()
{
	int testcase;
	
	cin >> testcase;

	while (testcase--)
	{
		cin >> n;

		for (int i = 0; i < n; ++i)
			cin >> y[i] >> x[i] >> r[i];

		convertToRange();

		int ret = solve();

		if (ret != inf)cout << ret << '\n';

		else cout << "IMPOSSIBLE" << '\n';
	}
	return 0;
}