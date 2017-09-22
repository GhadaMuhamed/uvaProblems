#include <bits/stdc++.h>
using namespace std;
#define oo 1e6
int dp[55][55];
int n;
int arr[60];
int solve(int i, int j) {
	if (j == i + 1)
		return 0;
	if (dp[i][j] != oo)
		return dp[i][j];
	for (int k = i + 1; k < j; k++)
		dp[i][j] = min(dp[i][j], solve(i, k) + solve(k, j) + (arr[j] - arr[i]));
	return dp[i][j];
}
int main() {
	int l;
	scanf("%d", &l);
	while (l) {
		for (int i = 0; i < 55; i++)
			for (int j = 0; j < 55; j++)
				dp[i][j] = oo;
		scanf("%d", &n);
		arr[0] = 0;
		for (int i = 1; i <= n; i++)
			scanf("%d", &arr[i]);
		arr[n + 1] = l;
		printf("The minimum cutting is %d.\n", solve(0, n + 1));
		scanf("%d", &l);
	}
}
