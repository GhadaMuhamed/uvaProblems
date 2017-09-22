#include <bits/stdc++.h>
using namespace std;
int n, h;
set<string> st;
void func(string s, int cnt) {
	if (cnt > h)
		return;
	if (s.size() == n) {
		if (cnt == h)
			st.insert(s);
		return;
	}
	func(s + '0', cnt);
	func(s + '1', cnt + 1);
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> h;
		func("", 0);
		for (set<string>::iterator it = st.begin(); it != st.end(); it++)
			cout << *it << endl;
		if (t)
		cout << endl;
		st.clear();
	}
}
