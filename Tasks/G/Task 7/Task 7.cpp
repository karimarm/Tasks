#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, num;
    char ch;
    cin >> n >> m;
    vector<pair<int, int>> vec(n);

    while (m--) {
        cin >> num >> ch;
        if (ch == '+')
            vec[num - 1].first++;
        else
            vec[num - 1].second++;
    }

    for (int i = 0; i < n; i++)
        cout << max(vec[i].first!=0 ? 1 : 0, vec[i].first - vec[i].second) << ' ';
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << vec[i].first << ' ';

    return 0;
}