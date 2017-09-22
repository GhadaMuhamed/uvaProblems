#include <bits/stdc++.h>
using namespace std;
int arr[40000];
int cnt[40000];
int dsu(int a) {
	return arr[a] = ((arr[a] == a) ? a : dsu(arr[a]));
}
int main() {
	int C;
	cin >> C;
	while (C--) {
		memset(cnt, 0, sizeof(cnt));
		int n, m;
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++)
			arr[i] = i;
		int a, b;
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &a, &b);
			a = dsu(a);
			b = dsu(b);
			arr[a] = b;
		}

		for (int i = 1; i <= n; i++)
			dsu(i);
		int mx = -1;
		for (int i = 1; i <= n; i++) {
			cnt[arr[i]]++;
			mx = max(cnt[arr[i]], mx);
		}
		cout << mx << endl;
	}
}
