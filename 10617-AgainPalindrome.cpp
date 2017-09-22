#include <bits/stdc++.h>
using namespace std;
bool isprime(int a) {
	for (int i = 2; i * i <= a; i++)
		if (a % i == 0)
			return false;
	return true;
}
int prime[1000000];
vector<int> primes;
void sieve() {
	arr[0] = 0;
	arr[1] = 0;
	for (int i = 2; i * i <= 1000000; i++)
		if (prime[i]) {
			primes.push_back(i);
			for (int j = 2; j * i <= 1000000; j++)
				prime[i * j] = 0;
		}
}
int main() {
	for (int i = 0; i <= 1000000; i++)
		prime[i] = 1;
	sieve();
	int n;
	cin >> n;
	int num = -1;
	for (int i = n - 1;; i--) {
		if (isprime(i)) {
			num = i;
			break;
		}
	}
	int sum = n - num;
	if (isprime(sum)) {
		cout << 2 << endl;
		cout << num << " " << sum << endl;
		return 0;
	}
	for (int i = 0; i < primes.size(); i++) {
		if (sum - primes[i] <= 1000000) {
			if (prime[sum - primes[i]]) {
				cout << 3 << endl;
				cout << sum << " " << num << " " << sum - prime[i] << endl;
				return 0;
			}
		} else if (isprime(sum-primes[i])) {
			cout << 3 << endl;
			cout << sum << " " << num << " " << sum - prime[i] << endl;
			return 0;
		}
	}
}
