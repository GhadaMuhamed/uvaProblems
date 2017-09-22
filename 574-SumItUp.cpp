#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int arr[13];
int t;
int n;
int ans;
set<string> st;
string convert(int x) {
	stringstream ss;
	ss << x;
	string str = ss.str();
	return str;
}
void func(int idx, int sum, string s) {
	if (idx == n) {
		if (sum == t)
			st.insert(s);
		return;
	}
	func(idx + 1, sum, s);
	func(idx + 1, sum + arr[idx], s + '+' + convert(arr[idx]));
}
int main() {
	cin >> t;
	while (t) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		func(0, 0, "");
		cout << "Sums of " << t << ":" << endl;
		if (st.size()) {
			set<string>::iterator it = st.end();
			it--;
			for (; it != st.begin(); it--) {
				cout << (*it).substr(1) << endl;
			}
			cout << (*it).substr(1) << endl;
		}
		if (st.size() == 0)
			cout << "NONE" << endl;
		st.clear();
		cin >> t;
	}
	cin >> n;
}
