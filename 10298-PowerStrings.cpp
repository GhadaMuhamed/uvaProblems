#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		int n = s.size();
		for (int i = 1; i <= n; i++) {
			if (n % i != 0)
				continue;
			bool t = false;
			for (int j = 0; j < i && !t; j++) {
				char z = s[j];
				for (int k = j + i; k < n; k += i)
					if (s[k] != z) {
						t = true;
						break;
					}
			}
			if (!t) {
				printf("%d\n", i);
				if (T)
					printf("\n");
				break;
			}
		}
	}
}
