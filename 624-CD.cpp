#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vi vec;
int k, n;
vi ans;
int fsum;
int arr[25];
void func(int idx, int sum) {
	if (sum > k)
		return;
	if (idx == n) {
		if (sum > fsum)
			ans = vec, fsum = sum;
		return;
	}
	vec.push_back(idx);
	func(idx + 1, sum + arr[idx]);
	vec.pop_back();
	func(idx + 1, sum);
}
int main() {
	string s;
	while (cin >> k >> n) {
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		func(0, 0);
		for (int i = 0; i < ans.size(); i++)
			cout << arr[ans[i]] << " ";
		cout << "sum:" << fsum << endl;
		fsum = 0;
		ans.clear();
	}
}
