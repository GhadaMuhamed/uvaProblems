#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
int n, m, s, d;
int len1[505];
int len2[505];
int g[502][502];
int rg[502][502];
void D(int start, bool anhy) {
	priority_queue<ii,vector<ii>,greater<ii> > q;
	q.push(ii(0,start));
	while (!q.empty()) {
		int cost = q.top().first;
		int cur = q.top().second;
		q.pop();
		if ((anhy && len1[cur] != -1 ) || (!anhy && len2[cur]!=-1))
		continue;
		if (anhy)
		len1[cur] = cost;
		else
		len2[cur] = cost;
		for (int i = 0; i < n; i++)
		{	if (anhy && g[cur][i] != -1)
			q.push(ii(cost+g[cur][i],i));
			if (!anhy && rg[cur][i]!=-1)
			q.push(ii(cost+rg[cur][i],i));
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	while (n && m) {
		memset(len1, -1, sizeof(len1));
		memset(len2, -1, sizeof(len2));
		memset(g, -1, sizeof(g));
		memset(rg, -1, sizeof(rg));
		scanf("%d%d", &s, &d);
		for (int i = 0; i < m; i++) {
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			g[x][y] = z;
			rg[y][x] = z;
		}
		D(s, true);
		D(d, false);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (g[i][j] != -1 && len1[i]!=-1 && len2[j]!=-1) {
					int sum = len1[i] + len2[j] + g[i][j];
					if (sum == len1[d])
						g[i][j] = -1;
				}
		memset(len1, -1, sizeof(len1));
		D(s, true);
		printf("%d\n", len1[d]);
		scanf("%d%d", &n, &m);
	}
}
