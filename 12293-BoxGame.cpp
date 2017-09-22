#include <bits/stdc++.h>
using namespace std;
int main() {
	long long n;
	cin >> n;
	while (n) {
		long long cnt = 0;
		long long tmp = -1;
		while (n != tmp) {
			tmp = n / 2;
			n = (n + 1) / 2;
			cnt++;
		}
		if (cnt & 1)
			cout << "Alice" << endl;
		else
			cout << "Bob" << endl;
		cin >> n;
	}
}
