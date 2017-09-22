#include <bits/stdc++.h>
using namespace std;
int coins[5] = { 1, 5, 10, 25, 50 };
long long dp[40000][5];
long long solve(int idx, int rem) {
	if (rem == 0)
		return 1;
	if (idx >= 5 || rem < 0)
		return 0;
	if (dp[rem][idx] != -1)
		return dp[rem][idx];
	return dp[rem][idx] = solve(idx, rem - coins[idx]) + solve(idx + 1, rem);
}
int main() {
	memset(dp, -1, sizeof(dp));
	int n;
	while (cin >> n) {
		long long ans = solve(0, n);
		if (n == 0)
			ans = 0;
		if (ans != 1)
			cout << "There are " << ans << " ways to produce " << n
					<< " cents change.";
		else
			cout << "There is only 1 way to produce" << n << "cents change.";
	}
}
