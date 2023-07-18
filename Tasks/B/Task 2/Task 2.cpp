#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int n, m;
	cin >> n >> m;

	vector<int> a(m), p(n - 1), q(m);
	vector<int> n_min(n, 1e6), n_max(n), n_coun(n);

	for (auto& i : a)
		cin >> i;
	for (auto& i : p)
		cin >> i;
	for (auto& i : q)
		cin >> i;

	for (int i = m - 1; i >= 0; --i) {
		if (n_min[q[i] - 1] > a[i])
			n_min[q[i] - 1] = a[i];
		if (n_max[q[i] - 1] < a[i])
			n_max[q[i] - 1] = a[i];
		n_coun[q[i] - 1]++;
	}

	for (int i = n - 1; i > 0; --i) {
		if (n_max[i] - n_min[i] + 1 != n_coun[i]) {
			cout << "NO\n";
			return 0;
		}

		if (n_min[p[i - 1] - 1] > n_min[i])
			n_min[p[i - 1] - 1] = n_min[i];
		if (n_max[p[i - 1] - 1] < n_max[i])
			n_max[p[i - 1] - 1] = n_max[i];
		n_coun[p[i - 1] - 1] += n_coun[i];
	}

	if (n_max[0] - n_min[0] + 1 == n_coun[0])
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}