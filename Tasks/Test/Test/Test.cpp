#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> a, q;
vector<pair<int, int>> p;

pair<int, int> foo(vector <pair<int, int>> ::iterator x) {
	int gmin_ = 1000000, gmax_ = 0, gcoun = 0;

	for (auto i = x; i != p.end() && (*i).first == (*x).first; ++i) {
		pair<int, int> new_pair;
		int min_ = 1000000, max_ = 0, coun = 0;
		int child = (*i).second;

		if (child < q[0]) {
			new_pair = foo(lower_bound(i, p.end(), make_pair(child, 0)));
		}
		else {
			int qi_index = lower_bound(q.begin(), q.end(), child) - q.begin();
			while (qi_index < m && q[qi_index] == child) {
				if (a[qi_index] > max_)
					max_ = a[qi_index];
				if (a[qi_index] < min_)
					min_ = a[qi_index];
				coun++;
				qi_index++;
			}

			if (max_ - min_ + 1 == coun)
				new_pair = make_pair(min_, max_);
			else
				new_pair = make_pair(0, 0);
		}

		if (new_pair.first == 0 && new_pair.second == 0) {
			return new_pair;
		}

		if (new_pair.first < gmin_)
			gmin_ = new_pair.first;
		if (new_pair.second > gmax_)
			gmax_ = new_pair.second;

		gcoun += new_pair.second - new_pair.first + 1;
	}

	if (gmax_ - gmin_ + 1 == gcoun)
		return make_pair(gmin_, gmax_);
	else
		return make_pair(0, 0);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	a.resize(m);
	p.resize(n - 1);
	q.resize(m);

	for (int i = 0; i < m; ++i)
		cin >> a[i];
	for (int i = 0; i < n - 1; ++i) {
		cin >> p[i].first;
		p[i].second = i + 2;
	}
	for (int i = 0; i < m; ++i)
		cin >> q[i];
	sort(p.begin(), p.end());
	
	pair<int, int> new_pair = foo(p.begin());
	if (new_pair.first == 1 && new_pair.second == m)
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}