#include <bits/stdc++.h>
using namespace std;
int indeg[105];
vector<int> graph[105];
int n, m;
vector<int> bfs() {
	vector<int> ans;
	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (indeg[i] == 0)
			q.push(i);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		ans.push_back(node);
		for (int i = 0; i < graph[node].size(); i++) {
			int child = graph[node][i];
			indeg[child]--;
			if (indeg[child] == 0)
				q.push(child);
		}
	}
	return ans;
}
int main() {
	cin >> n >> m;
	while (n != 0 || m != 0) {
		for (int i = 0; i < m; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			graph[x].push_back(y);
			indeg[y]++;
		}
		vector<int> ans = bfs();
		for (int i = 0; i < ans.size(); i++)
			printf("%d ", ans[i]);
		printf("\n");
		memset(indeg, 0, sizeof(indeg));
		for (int i = 1; i <= n; i++)
			graph[i].clear();
		cin >> n >> m;
	}

}
