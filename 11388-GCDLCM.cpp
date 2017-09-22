#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		long long a, b;
		scanf("%lld %lld", &a, &b);
		if (b % a != 0) {
			printf("-1\n");
			continue;
		}
		printf("%lld %lld\n", a, b);
	}
}
