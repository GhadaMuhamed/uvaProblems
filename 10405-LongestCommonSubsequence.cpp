#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
string s;
string ss;
int solve(int idx1, int idx2) {
	if (idx1 == int(s.size()) || idx2 == int(ss.size()))
		return 0;
	if (dp[idx1][idx2] != -1)
		return dp[idx1][idx2];
	if (s[idx1] == ss[idx2]) {
		if (dp[idx1][idx2] == -1)
			dp[idx1][idx2] = 0;
		return dp[idx1][idx2] = solve(idx1 + 1, idx2 + 1) + 1;
	} else
		return dp[idx1][idx2] = max(solve(idx1 + 1, idx2),
				solve(idx1, idx2 + 1));
}
int main() {

	while (getline(cin, s)) {
		getline(cin, ss);
		if (int(s.size()) == 0 || int(ss.size()) == 0) {
			cout << 0 << endl;
			continue;
		}
		memset(dp, -1, sizeof(dp));
		cout << solve(0, 0) << endl;
	}
}
