#include <bits/stdc++.h>
using namespace std;
long long GCD(long long a, long long b) {
	if (b == 0)
		return a;
	else
		return GCD(b, a % b);
}
int main() {
	int t;
	cin >> t;
	for (int T = 1; T <= t; T++) {
		long long x, n, y, m;
		scanf("%lld %lld %lld %lld", &x, &n, &y, &m);
		long long num1 = x;
		long long num2 = 0;
		for (int i = 0; i < n; i++) {
			if (num1 > num2) {
				num2 += num1;
			} else
				num1 += num2;
		}
		if (num1 > num2)
			num1 += y;
		else
			num2 += y;
		printf("Case %d: %lld\n", T, GCD(num1, num2));
	}
}
