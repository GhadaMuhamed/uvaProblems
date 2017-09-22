#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
bool prime[100];
bool vis[17];
int n;
vector<vi> ans;
void sieve() {
	for (int i = 2; i < 100; i++)
		prime[i] = true;
	for (int i = 2; i * i <= 100; i++)
		if (prime[i])
			for (int j = 2; j * i < 100; j++)
				prime[i * j] = false;
}
vi vec;
void func(int idx, int last) {
	if (idx == n) {
		if (prime[vec[vec.size() - 1] + 1])
			ans.push_back(vec);
		return;
	}
	for (int i = 2; i <= n; i++) {
		if (vis[i])
			continue;
		if (prime[i + last]) {
			vis[i] = true;
			vec.push_back(i);
			func(idx + 1, i);
			vec.pop_back();
			vis[i] = false;
		}
	}

}
int main() {
	sieve();
	int cnt = 1;
	while (cin >> n) {
		if (cnt > 1)
			cout << endl;
		cout << "Case " << cnt << ":" << endl;
		if (n == 0) {

		} else {
			func(1, 1);
			for (int i = 0; i < ans.size(); i++) {
				cout << 1 << " ";

				for (int j = 0; j < ans[i].size(); j++) {
					if (j > 0)
						cout << " ";
					cout << ans[i][j];
				}
				cout << endl;

			}
		}
		cnt++;
		ans.clear();
	}
}
