#include <bits/stdc++.h>
using namespace std;
vector<int> arra[2000];
vector<int> arrb[2000];

int main() {
	int t;
	cin >> t;
	while (t--) {
		string a, b;
		cin >> a >> b;
		int idx = 0;
		vector<int> vec;
		int cnt = 0;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] == 'p') {
				idx = max((int) arra[idx].size() + 1, (int) idx + 1);
				vec.push_back(idx);
			} else if (a[i] == 'e')
				cnt++, arra[idx].push_back(3000);
			else if (a[i] == 'f')
				cnt++, arra[idx].push_back(4000);
			if (cnt == 4)
				vec.pop_back(), idx = vec[vec.size() - 1];
		}
		idx = 0;
		vec.clear();
		cnt = 0;
		for (int i = 0; i < b.size(); i++) {
			if (b[i] == 'p') {
				idx = arrb[idx].size() + 1;
				vec.push_back(idx);
			} else if (b[i] == 'e')
				cnt++, arrb[idx].push_back(3000);
			else if (b[i] == 'f')
				cnt++, arrb[idx].push_back(4000);
			if (cnt == 4)
				vec.pop_back(), idx = vec[vec.size() - 1];
		}
		for (int i = 0; i < 50; i++, cout << i << " " << endl)
			for (int j = 0; j < arra[i].size(); j++) {
				cout << arra[i][j] << " ";
			}
	}
}
