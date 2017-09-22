#include <bits/stdc++.h>
using namespace std;
int fact[13];
int d[13];
int n, m;
long long k;
int main() {
	int t;
	cin >> t;
	fact[1] = 1;
	for (int i = 2; i < 12; i++)
		fact[i] = fact[i - 1] * i;
	d[1] = 0, d[2] = 1;
	for (int i = 3; i < 12; i++)
		d[i] = i * d[i - 1] + ((i & 1) ? -1 : 1);
	while (t--) {
		scanf("%d", &n);
		printf("%d/%d\n", d[n], fact[n]);
	}
}
