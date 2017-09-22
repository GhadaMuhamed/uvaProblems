#include <bits/stdc++.h>
using namespace std;
int n;
int sum[105][105];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			int elm;
			cin >> elm;
			sum[i][j] = sum[i][j - 1] + elm;
		}
	int ans = -1000000000;
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++) {
			int bsty = -1000000000;
			int best = -1000000000;
			for (int k = 1; k <= n; k++) {
				int cur = sum[k][j] - sum[k][i - 1];
				if (bsty < 0)
					bsty = cur;
				else
					bsty = cur + bsty;
				if (bsty > best)
					best = bsty;
			}
			if (best > ans)
				ans = best;
		}
	cout << ans << endl;
}
