#include <bits/stdc++.h>
using namespace std;
pair<string, string> p[100005];
int dsu(int s, int* arr) {
	return arr[s] = ((arr[s] == s) ? s : dsu(arr[s], arr));
}
int findpar(int a, int b, int* arr2, int* arr) {
	int x = dsu(a, arr);
	int y = dsu(b, arr);
	if (x != y) {
		arr[y] = x;
		arr2[x] += arr2[y];
	}
		return arr2[x];
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		map<string, int> mp;
		int f;
		cin >> f;
		int cnt = 1;
		for (int i = 0; i < f; i++) {
			string a, b;
			cin >> a >> b;
			p[i].first = a;
			p[i].second = b;
			if (mp[a] == 0) {
				mp[a] = cnt;
				cnt++;
			}
			if (mp[b] == 0) {
				mp[b] = cnt;
				cnt++;
			}
		}
		int* arr = new int[cnt];
		for (int i = 1; i < cnt; i++)
			arr[i] = i;
		int* arr2 = new int[cnt];
		for (int i = 1; i < cnt; i++)
			arr2[i] = 1;

		for (int i = 0; i < f; i++) {
			cout << findpar(mp[p[i].first], mp[p[i].second], arr2, arr) << endl;
		}

	}
}
