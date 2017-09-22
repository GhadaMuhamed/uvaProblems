#include <bits/stdc++.h>
using namespace std;
int arr[5];
bool fnd = false;
void func(int idx, int sum) {
	if (idx == 5) {
		if (sum == 23)
			fnd = true;
		return;
	}
	func(idx + 1, sum + arr[idx]);
	func(idx + 1, sum - arr[idx]);
	func(idx + 1, sum * arr[idx]);
}
int main() {
	for (int i = 0; i < 5; i++)
		cin >> arr[i];
	while (1) {
		bool exit = true;
		for (int i = 0; i < 5; i++)
			if (arr[i] != 0)
				exit = false;
		if (exit)
			break;
		func(1, arr[0]);
		while (next_permutation(arr, arr + 5)) {
			func(1, arr[0]);
			if (fnd)
				break;
		}
		if (fnd)
			cout << "Possible" << endl;
		else
			cout << "Impossible" << endl;
		for (int i = 0; i < 5; i++)
				cin >> arr[i];
		fnd=false;
	}
}
