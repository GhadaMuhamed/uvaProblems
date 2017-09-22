#include <bits/stdc++.h>
using namespace std;
long long oo = 1e9;
#define ii pair<int ,int>
long long dijkstra(int start, int target, vector<pair<int, int> > arr[]) {
	vector<long long> sp(30000, oo);
	priority_queue<ii,vector<ii>,greater<ii> > q;
	q.push( { 0, start });
	while (!q.empty()) {
		int w = q.top().first;
		int cur = q.top().second;
		if (cur == target)
			return w;
		q.pop();
		if (sp[cur] != oo)
			continue;
		sp[cur] = w;
		for (int i = 0; i < int(arr[cur].size()); i++) {
			int child = arr[cur][i].first;
			int cost = arr[cur][i].second;
			q.push( { w + cost, child });
		}
	}
	return -1;
}
int main() {
	int t;
	scanf("%d", &t);
	for (int j = 1; j <= t; j++) {
		vector<pair<int, int> > arr[30000];

		int n, m, s, t;
		scanf("%d %d %d %d", &n, &m, &s, &t);
		for (int i = 0; i < m; i++) {
			int a, b, w;
			scanf("%d %d %d", &a, &b, &w);
			arr[a].push_back( { b, w });
			arr[b].push_back( { a, w });
		}
		long long ans = dijkstra(s, t, arr);
		printf("Case #%d: ", j);
		if (ans != -1)
			printf("%lld\n", ans);
		else
			printf("unreachable\n");
	}
}
