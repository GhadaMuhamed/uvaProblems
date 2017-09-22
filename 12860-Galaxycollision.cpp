#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> g[50005];
map<pair<int, int>, int> mp;
pair<int, int> points[50004];
int ans[50004];
int cnt[2];
void dfs(int v,int par ) {
	ans[v] = 1;
	cnt[par]++;
	for (int i = 0; i < g[v].size(); i++)
		if (ans[g[v][i]] == -1)
			dfs(g[v][i], par^1);
}
int main() {
	while (cin >> n) {
		for (int i = 1; i <= n; i++) {
			g[i].clear();
			scanf("%d%d", &points[i].first, &points[i].second);
			mp[ { points[i].first, points[i].second }] = i;
		}
		for (int i = 1; i <= n; i++) {
			int X = points[i].first;
			int Y = points[i].second;
			for (int j = -5; j <= 5; j++)
				for (int k = -5; k <= 5; k++) {
					int curX = X + j;
					int curY = Y + k;
					if (((X - curX) * (X - curX) + (Y - curY) * (Y - curY) > 25)
							|| ((X - curX) * (X - curX)
									+ (Y - curY) * (Y - curY) == 0))
						continue;
					if (mp.count( { curX, curY }))
						g[i].push_back(mp[ { curX, curY }]), g[mp[ { curX, curY }]].push_back(
								i);
				}
		}
		memset(ans, -1, sizeof(ans));
		ans[0] = 1;
		int res=0;
		for (int i = 1; i <= n; i++)
			if (ans[i] == -1) {
				memset(cnt,0,sizeof(cnt));
					dfs(i, 0);
					res+=min(cnt[0],cnt[1]);
			}

		printf("%d\n", res);
		mp.clear();
	}
}
