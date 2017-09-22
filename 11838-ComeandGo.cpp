#include <bits/stdc++.h>
using namespace std;
stack<int> st;
int vis[2005];
vector<int> graph[2005];
vector<int> reversed[2005];
int n, m;
void dfs1(int node) {
	vis[node] = 1;
	for (int i = 0; i < graph[node].size(); i++)
		if (!vis[graph[node][i]])
			dfs1(graph[node][i]);
	st.push(node);
}
void dfs2(int node) {
	vis[node] = 1;
	for (int i = 0; i < reversed[node].size(); i++)
		if (!vis[reversed[node][i]])
			dfs2(reversed[node][i]);
}
bool SCC() {
	for (int i = 1; i <= n; i++)
		if (!vis[i])
			return false;
	memset(vis, 0, sizeof(vis));
	int cur = st.top();
	dfs2(cur);
	for (int i = 1; i <= n; i++)
		if (!vis[i])
			return false;
	return true;
}
int main() {
	cin >> n >> m;
	while (n != 0 || m != 0) {
		for (int i = 0; i < m; i++) {
			int p, u, v;
			scanf("%d%d%d", &u, &v, &p);
			if (p == 2) {
				graph[v].push_back(u);
				reversed[u].push_back(v);
			}
			graph[u].push_back(v);
			reversed[v].push_back(u);
		}
		dfs1(1);
		printf("%d\n", SCC());
		cin >> n >> m;
		while (!st.empty())
			st.pop();
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= n; i++) {
			graph[i].clear();
			reversed[i].clear();
		}
	}
}
