#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
char s[1005];
int solve(int i, int j, char s[]) {
	if (i > j)
		return 0;
	if (i == j)
		return 1;
	if (dp[i][j] != -1)
		return dp[i][j];
	if (s[i] == s[j]) {
		if (dp[i][j] == -1)
			dp[i][j] = 0;
		return dp[i][j] = solve(i + 1, j - 1, s) + 2;
	} else
		return dp[i][j] = max(solve(i + 1, j, s), solve(i, j - 1, s));
}
int main() {
	int t;
	cin >> t;
	getchar();
	while (t--) {
		memset(dp, -1, sizeof(dp));
		gets(s);
		if (int(strlen(s)) == 0)
			cout << 0 << endl;
		else
			cout << solve(0, strlen(s) - 1, s) << endl;

	}

}
