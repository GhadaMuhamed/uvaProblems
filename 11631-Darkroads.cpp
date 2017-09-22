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
long long ans = 0;
node arr[300000];
int arr2[300000];
int dsu(int a) {
	return arr2[a] = ((arr2[a] == a) ? a : dsu(arr2[a]));
}
void solve(const node& n1) {
	int x = dsu(n1.a);
	int y = dsu(n1.b);
	if (x != y) {
		arr2[x] = y;
		ans += n1.w;
	}
}
int main() {
	cin >> n >> m;
	while (n || m) {
		long long sum = 0;
		for (int i = 0; i < m; i++) {
			int x, y;
			long long z;
			scanf("%d %d %lld", &x, &y, &z);
			arr[i].a = x;
			arr[i].b = y;
			arr[i].w = z;
			sum += z;
		}
		sort(arr, arr + m, cmp);
		for (int i = 0; i < n; i++)
			arr2[i] = i;
		for (int i = 0; i < m; i++)
			solve(arr[i]);
		cout << sum - ans << endl;
		ans = 0;
		cin >> n >> m;
	}
}
