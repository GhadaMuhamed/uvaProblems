#include <bits/stdc++.h>
using namespace std;
int arr[20];
int t;
vector<int> vec;
void func(int idx) {
	if (vec.size() > 6)
		return;
	if (idx == t) {
		if (vec.size() == 6) {
			for (int i = 0; i < vec.size(); i++) {
				if (i > 0)
					cout << " ";
				cout << vec[i];
			}
			cout << endl;
		}
		return;
	}
	vec.push_back(arr[idx]);
	func(idx + 1);
	vec.pop_back();
	func(idx + 1);

}
int main() {
	cin >> t;
	bool f = false;
	while (t) {
		if (f)
			cout << endl;
		f = true;
		for (int i = 0; i < t; i++)
			cin >> arr[i];
		func(0);
		cin >> t;
	}

}
