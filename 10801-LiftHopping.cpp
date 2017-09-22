#include <bits/stdc++.h>
using namespace std;
struct node {
	int child, cost, type;
	node(int ch, int co, int ty) :
			child(ch), cost(co), type(ty) {
	}
	bool operator <(const node &b) const {
		return (cost > b.cost);
	}
};
#define oo 1e9
int n, k;
int D(vector<node> arr[], int t[]) {
	int sp[100][6];
	memset(sp, -1, sizeof(sp));
	priority_queue<node> q;
	q.push(node(0, 0, 0));
	while (!q.empty()) {
		int cur = q.top().child;
		int w = q.top().cost;
		int elv = q.top().type;
		q.pop();
		if (sp[cur][elv] != -1)
			continue;
		sp[cur][elv] = w;
		for (int i = 0; i < int(arr[cur].size()); i++) {
			int g = 0;
			if (arr[cur][i].type != elv && cur != 0)
				g = 60;
			q.push(
					node(arr[cur][i].child, w + arr[cur][i].cost + g,
							arr[cur][i].type));
		}
	}
	int mn = -1;
	for (int i = 0; i <= n; i++)
		if (sp[k][i] != -1)
			mn = min(mn, sp[k][i]);
	return mn;
}
int main() {

	while (cin >> n >> k) {
		vector<node> arr[100];
		int t[6];
		for (int i = 1; i <= n; i++)
			cin >> t[i];
		cin.ignore();
		for (int i = 1; i <= n; i++) {
			int last = -1;
			string s;
			getline(cin, s);
			stringstream ss(s);
			int x;
			while (ss >> x) {
				if (last != -1) {
					arr[last].push_back(node(x, (x - last) * t[i], i));
					arr[x].push_back(node(last, (x - last) * t[i], i));
				}
				last = x;
			}
		}
		int ans = D(arr, t);
		if (ans == -1)
			puts("IMPOSSIBLE\n");
		else
			printf("%d\n", ans);
	}
}
