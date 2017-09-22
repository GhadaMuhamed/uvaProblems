#include <bits/stdc++.h>
using namespace std;
struct node {
	int first, second, par;
	node(int f, int s, int p) :
			first(f), second(s), par(p) {
	}
	bool operator <(node & n2) {
		return (second < n2.second);
	}
};
#define ii pair<int,int>
int vis[500];
vector<ii> g[500];
int D(int start) {
	int mx = -1;
	priority_queue<ii,vector <ii>,greater<ii> > q;
	q.push( { 0, start });
	while (!q.empty()) {
		int cost = q.top().first;
		int cur = q.top().second;
		q.pop();
		if (vis[cur] != -1)
			continue;
		vis[cur] = cost;
		mx = max(mx, cost);
		for (int i = 0; i < g[cur].size(); i++)
			q.push( { cost + g[cur][i].second, g[cur][i].first });
	}
	return mx;
}
int main() {
	int s, c;
	while (scanf("%d%d", &s, &c) && (s || c)) {
		map<string, int> mp;
		mp.clear();
		for (int i = 1; i <= s; i++) {
			string str;
			cin >> str;
			mp[str] = i;
			g[i].clear();
		}
		for (int i = 0; i < c; i++) {
			string str1, str2;
			int z;
			cin >> str1 >> str2 >> z;
			int f = mp[str1];
			int sec = mp[str2];
			g[f].push_back( { sec, z });
			g[sec].push_back( { f, z });
		}
		string start;
		cin >> start;
		memset(vis, -1, sizeof(vis));
		int ans = D(mp[start]);
		for (int i = 1; i <= s; i++)
			if (vis[i] == -1)
				ans = -1;
		(ans == -1) ? printf("Impossible\n") : printf("%d\n", ans);
	}
}
