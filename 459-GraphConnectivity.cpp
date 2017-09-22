#include <bits/stdc++.h>
using namespace std;
int arr[30];
int dsu(int a) {
	return arr[a] = ((arr[a] == a) ? a : dsu(arr[a]));
}
void solve(int a, int b) {
	int x = dsu(a);
	int y = dsu(b);
	if (x != y) {
		arr[x] = y;
	}
}
int main() {
	int t;
	cin >> t;
	int cnt = 0;
	while (t--) {
		cnt++;
		char a;
		cin >> a;
		int num = a - 'A' + 1;
		for (int i = 0; i < num; i++)
			arr[i] = i;
		string s;
		cin.ignore();
		while (1) {
			if (!getline(cin, s) || s.empty())
				break;
			char x = s[0];
			char y = s[1];
			solve(x - 'A', y - 'A');
		}
		for (int i = 0; i < num; i++)
			dsu(i);
		set<int> st;
		for (int i = 0; i < num; i++)
			st.insert(arr[i]);
		cout << st.size() << endl;
		if (t)
			cout << endl;
	}
}
