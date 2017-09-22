#include <bits/stdc++.h>
using namespace std;
long long n;
int main() {
	while (scanf("%lld", &n) && (n)) {
		long long a = 0;
		long long b = 0;
		int d = 1;
		for (int i = 0; i < 33; i++) {
			if (!((1LL << i) & n))
				continue;
			if (d)
				a |= (1LL << i);
			else
				b |= (1LL << i);
			d = !d;
		}
		printf("%lld %lld\n", a, b);
	}
}
