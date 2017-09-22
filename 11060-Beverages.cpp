#include <bits/stdc++.h>
using namespace std;
map<string, int> indeg;
map<string, vector<string> > graph;
int n, m;
map<string, int> ap;
vector<string> bfs() {
	vector<string> ans;
	priority_queue<pair<int, string>, vector<pair<int, string> >,
			greater<pair<int, string> > > q;
	for (map<string, int>::iterator it = indeg.begin(); it != indeg.end(); it++)
		if (it->second == 0)
			q.push(make_pair(ap[it->first], it->first));
	while (!q.empty()) {
		string cur = q.top().second;
		q.pop();
		ans.push_back(cur);
		for (int i = 0; i < graph[cur].size(); i++) {
			string child = graph[cur][i];
			indeg[child]--;
			if (indeg[child] == 0)
				q.push(make_pair(ap[child], child));
		}
	}
	return ans;
}
int main() {
	int cnt = 1;
	while (cin >> n) {
		int num = 1;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			ap[s] = num++;
			indeg[s] = 0;
		}
		cin >> m;
		for (int i = 0; i < m; i++) {
			string a, b;
			cin >> a >> b;
			indeg[b]++;
			graph[a].push_back(b);
		}
		vector<string> ans = bfs();
		cout << "Case #" << cnt
				<< ": Dilbert should drink beverages in this order: ";
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i];
			if (i != ans.size() - 1)
				cout << " ";
		}
		cout << "." << endl << endl;
		indeg.clear();
		graph.clear();
		ap.clear();
		cnt++;
	}
}
