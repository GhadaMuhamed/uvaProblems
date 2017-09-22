#include <bits/stdc++.h>
using namespace std;
int dp[300][40];
int arr[40][40];
int size[40];
int solve(int i, int sum, int t, int num) {
	if (sum <= t && i == num)
		return sum;
	if (sum > t || i >= num)
		return 0;
	if (dp[sum][i] != -1)
		return dp[sum][i];
	for (int j = 0; j < size[i]; j++) {
		dp[sum][i] = max(dp[sum][i], solve(i + 1, sum + arr[i][j], t, num));
	}
	return dp[sum][i];
}
int main() {
	int t;
	cin >> t;
	while (t--) {

		memset(dp, -1, sizeof(dp));
		int m, c;
		scanf("%d %d", &m, &c);
		for (int i = 0; i < c; i++) {
			cin >> size[i];
			for (int j = 0; j < size[i]; j++)
				cin >> arr[i][j];
		}
		int ans = solve(0, 0, m, c);
		if (ans == 0)
			printf("no solution\n");
		else
			printf("%d\n", ans);

	}
}
