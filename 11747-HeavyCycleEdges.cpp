#include <bits/stdc++.h>
using namespace std;
struct node {
	int a;
	int b;
	long long w;
};
bool cmp(const node &n1, const node &n2) {
	return (n1.w < n2.w);
}
int n, m;
node arr[1005];
int arr2[1005];
vector<long long> ans;
int dsu(int a) {
	return arr2[a] = ((arr2[a] == a) ? a : dsu(arr2[a]));
}
int solve(const node& n1) {
	int x = dsu(n1.a);
	int y = dsu(n1.b);
	if (x == y)
		ans.push_back(n1.w);
	else
		arr2[x] = y;
}
int vis[1005];
int main() {
	cin >> n >> m;
	while (n || m) {
		for (int i = 0; i < m; i++) {
			int x, y;
			long long z;
			cin >> x >> y >> z;
			arr[i].a = x;
			arr[i].b = y;
			arr[i].w = z;
			vis[x] = 1;
			vis[y] = 1;
		}
		sort(arr, arr + m, cmp);
		for (int i = 0; i < n; i++)
			arr2[i] = i;
		for (int i = 0; i < m; i++)
			solve(arr[i]);
		if (ans.size() == 0)
			cout << "forest";
		else
			for (int i = 0; i < ans.size(); i++) {
				cout << ans[i];
				if (i != ans.size() - 1)
					cout << " ";
			}
		cout << endl;
		ans.clear();
		memset(vis, 0, sizeof(vis));
		cin >> n >> m;
	}
}
