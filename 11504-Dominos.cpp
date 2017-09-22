#include <bits/stdc++.h>
using namespace std;
stack<int> st;
int vis[100005];
vector<int> graph[100005];
int n, m;
int cnt = 0;
int ans = 0;
void dfs(int node, bool t) {
	vis[node] = 1;
	for (int i = 0; i < graph[node].size(); i++)
		if (!vis[graph[node][i]])
			dfs(graph[node][i], t);
	if (t)
		st.push(node);
}

void clear() {
	for (int i = 1; i <= n; i++)
		graph[i].clear();
	memset(vis, 0, sizeof(vis));
	ans = 0;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			graph[x].push_back(y);
		}
		for (int i = 1; i <= n; i++) {
			if (vis[i] == 0)
				dfs(i, true);
		}
		memset(vis, 0, sizeof(vis));
		while (!st.empty()) {
			int cur = st.top();
			st.pop();
			if (vis[cur])
				continue;
			vis[cur] = 1;
			dfs(cur, false);
			ans++;
		}
		printf("%d\n", ans);
		clear();
	}
}
