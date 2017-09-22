#include <bits/stdc++.h>
using namespace std;
int n, m;
int par[200005];
long long sum[200005];
int cnt[200005];
int unitany(int a) {
	return par[a] = ((par[a] == a) ? a : unitany(par[a]));
}
void uni(int a, int b) {
	int x = unitany(a);
	int y = unitany(b);
	if (x == y)
		return;
	cnt[par[y]] += cnt[par[x]];
	sum[par[y]] += sum[par[x]];
	par[x] = par[y];
}
void move(int a, int b) {
	int x = unitany(b);
	int y = unitany(a);
	if (x == y)
		return;
	cnt[y]--;
	sum[y] -= a;
	sum[x] += a;
	cnt[x]++;
	par[a] = x;
}
int main() {
	while (cin >> n >> m) {

		for (int i = 1, j = n + 1; i <= n; i++, j++) {
			par[i] = j;
			par[j] = j;
			sum[i] = 0;
			sum[j] = i;
			cnt[j] = 1;
		}

		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a;
			if (a == 3)
				cin >> b;
			else
				cin >> b >> c;
			if (a == 1)
				uni(b, c);
			else if (a == 2)
				move(b, c);
			else
				cout << cnt[unitany(b)] << " " << sum[unitany(b)] << endl;
		}

	}
}
