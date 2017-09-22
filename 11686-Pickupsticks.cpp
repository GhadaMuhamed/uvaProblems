#include <bits/stdc++.h>
using namespace std;
int indeg[1000005];
vector<int> graph[1000005];
int main() {
	int n, m;
	cin >> n >> m;
	while (n != 0 || m != 0) {
		memset(indeg, 0, sizeof(indeg));
		for (int i = 1; i <= n; i++)
			graph[i].clear();
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			indeg[b]++;
			graph[a].push_back(b);
		}
		queue<int> q;
		for (int i = 1; i <= n; i++) {
			if (indeg[i] == 0)
				q.push(i);
		}
		vector<int> ans;
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			ans.push_back(cur);
			for (int i = 0; i < graph[cur].size(); i++) {
				int child = graph[cur][i];
				indeg[child]--;
				if (indeg[child] == 0)
					q.push(child);
			}
		}
		if (ans.size() < n)
			printf("IMPOSSIBLE\n");
		else
			for (int i = 0; i < ans.size(); i++)
				cout << ans[i] << endl;
		cin >> n >> m;
	}

}
