#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	long long ans = 0;
	int idx = s.size() - 1;
	while (idx > 0) {
		if (s[idx] == '1') {
			ans++;
			while (s[idx] == '1' && idx >= 0) {
				ans++;
				idx--;
			}
			if (idx < 0)
				break;
			s[idx] = '1';
		} else {
			while (s[idx] == '0') {
				ans++;
				idx--;
			}
		}
	}
	cout << ans << endl;
}
