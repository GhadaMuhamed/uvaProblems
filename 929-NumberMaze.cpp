#include <bits/stdc++.h>
using namespace std;
struct node {
	int i, j, cost;
	node(int ii, int jj, int ccost) :
			i(ii), j(jj), cost(ccost) {
	}
	bool operator <(const node &b) const {
		return (cost > b.cost);
	}
};
long long oo = 1e9;
#define ii pair<int ,int>
int di[] = { 0, 0, 1, -1 };
int dj[] = { 1, -1, 0, 0 };
int arr[1005][1005];
int n, m;
bool isvalid(int iii, int jjj) {
	return (iii >= 0 && jjj >= 0 && iii < n && jjj < m);
}
long long dijkstra(int si, int sj, int lasti, int lastj) {
	int sp[1005][1005];
	for (int i = 0; i <= lasti; i++)
		for (int j = 0; j <= lastj; j++)
			sp[i][j] = oo;
	priority_queue<node> q;
	q.push(node(si, sj, 0));
	while (!q.empty()) {
		int w = q.top().cost;
		int curi = q.top().i;
		int curj = q.top().j;
		q.pop();
		if (sp[curi][curj] != oo)
			continue;
		sp[curi][curj] = w + arr[curi][curj];
		if (curi == lasti && curj == lastj)
			return sp[curi][curj];
		for (int ig = 0; ig < 4; ig++) {
			if (isvalid(curi + di[ig], curj + dj[ig])) {
				q.push(node(curi + di[ig], curj + dj[ig], sp[curi][curj]));
			}
		}
	}
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		scanf("%d", &m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf("%d", &arr[i][j]);
		printf("%d\n", dijkstra(0, 0, n - 1, m - 1));
	}
}
