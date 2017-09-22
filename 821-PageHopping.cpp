#include <bits/stdc++.h>
using namespace std;
#define oo 1e9
int adj[1010][1010];
int in[105];
void warshall() {
	for (int k = 1; k <= 100; k++)
		for (int i = 1; i <= 100; i++)
			for (int j = 1; j <= 100; j++) {
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
}
int main() {
	int cnt = 1;
	while (1) {
		for (int i = 1; i <= 100; i++)
			for (int j = 1; j <= 100; j++) {
				adj[i][j] = oo;
			}
		memset(in, 0, sizeof(in));
		int a, b;
		map<int, int> mp;
		scanf("%d %d", &a, &b);
		if (a == 0 && b == 0)
			break;
		mp[a] = 1;
		in[a] = 1;
		mp[b] = 1;
		in[b] = 1;
		while (1) {
			adj[a][b] = 1;
			scanf("%d %d", &a, &b);
			if (a == 0 && b == 0) {
				warshall();
				long double sum = 0;
				for (int i = 1; i <= 100; i++)
					for (int j = 1; j <= 100; j++) {
						if (i == j)
							continue;
						if (in[i] && in[j])
							sum += adj[i][j];
					}
				long double num = (mp.size() * (mp.size() - 1));
				cout << "Case " << cnt << ": average length between pages = "
						<< fixed << setprecision(3) << sum / num << " clicks"
						<< endl;
				break;
			}
			mp[a] = 1;
			in[a] = 1;
			mp[b] = 1;
			in[b] = 1;
		}
		cnt++;
	}
}
