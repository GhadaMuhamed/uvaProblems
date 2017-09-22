#include <bits/stdc++.h>
using namespace std;
int n, m;
long long cost;
long long arr[105][105];
int main() {
	int t;
	cin >> t;
	for  (int T=1;T<=t;T++) {
		scanf("%d%d%lld", &n, &m, &cost);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				scanf("%lld", &arr[i][j]);
		for (int i = 1; i <= n; i++)
			for (int j = 2; j <= m; j++)
				arr[i][j] += arr[i][j - 1];
		for (int i = 2; i <= n; i++)
			for (int j = 1; j <= m; j++)
				arr[i][j] += arr[i - 1][j];
		int len = 0;
		long long ans = cost;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				for (int k = i; k <= n; k++)
					for (int l = j; l <= m; l++) {
						long long sum = arr[k][l] - arr[i - 1][l]
								- arr[k][j - 1] + arr[i - 1][j - 1];
						int lll = (k - i + 1) * (l - j + 1);
						if ((lll > len && sum <= cost)
								|| (lll == len && sum < ans))
							ans = sum, len = lll;
					}
		printf("Case #%d: %d %lld\n",T, len, ans);
	}
}
