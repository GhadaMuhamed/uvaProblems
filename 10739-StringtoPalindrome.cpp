#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
string s;
int solve(int i, int j) {
	if (i >= j)
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];
	dp[i][j] = 0;
	if (s[i] == s[j]) {
		return dp[i][j] = solve(i + 1, j - 1);
	} else {
		return dp[i][j] = min(solve(i + 1, j),
				min(solve(i, j - 1), solve(i + 1, j - 1))) + 1;
	}
}
int main() {
	int t;
	cin >> t;
	cin.ignore();
	int ans;
	for (int i = 1; i <= t; i++) {
		getline(cin, s);
		if (int(s.size() == 0)) {
			cout << 0 << endl;
			continue;
		}
		memset(dp, -1, sizeof(dp));
		ans = solve(0, int(s.size()) - 1);
		cout << "Case " << i << ": " << ans << endl;
	}
}
