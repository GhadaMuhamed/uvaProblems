#include <bits/stdc++.h>
using namespace std;
vector<int> g[105];
int arr[105];
bool cmp(int x, int y) {
	return (arr[x] > arr[y]);
}
int main() {
	int t;
	cin >> t;
	int cnt = 1;
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]),g[i].clear();
		for (int i = 0; i < m; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			g[x].push_back(y);
		}
		for (int i = 0; i < n; i++)
			sort(g[i].begin(), g[i].end(), cmp);
		int cur = 0;
		int ans = 0;
		while (g[cur].size() != 0) {
			ans += arr[g[cur][0]];
			cur = g[cur][0];
		}
		cout << "Case " << cnt << ": " << ans << " " << cur << endl;
		cnt++;
	}
}
