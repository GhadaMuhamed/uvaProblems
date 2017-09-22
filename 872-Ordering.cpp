#include <bits/stdc++.h>
using namespace std;
int arr[26][26];
int indeg[26];
int cnt ;
vector<string> ans1;
void func(string tmp) {
	for (int i = 0; i < 26; i++) {
		bool f = false;
		if (indeg[i] == -1)
			continue;
		int c = 0;
		for (int j = 0; j < tmp.size(); j++) {
			if (arr[i][tmp[j] - 'A'])
				c++;
			if (tmp[j] - 'A' == i) {
				f = true;
				break;
			}
		}
		if (f)
			continue;
		if (indeg[i] - c == 0) {
			string sss = tmp;
			sss += (i + 'A');
			func(sss);
		}

	}

	if (tmp.size() == cnt)
		ans1.push_back(tmp);
}
int main() {
	int t;
	cin >> t;
	cin.ignore();
	while (t--) {
		cin.ignore();

		cnt=0;
		ans1.clear();
		memset(indeg, -1, sizeof(indeg));
		memset(arr, 0, sizeof(arr));
		string m;
		getline(cin, m);
		for (int i = 0; i < m.size(); i++)
			if (m[i] != ' ')
				indeg[m[i] - 'A'] = 0, cnt++;
		string s;
		getline(cin, s);
		for (int i = 0; i < s.size(); i += 4) {
			arr[s[i + 2] - 'A'][s[i] - 'A'] = 1;
			indeg[s[i + 2] - 'A']++;
		}
		func("");
		for (int i = 0; i < ans1.size(); i++) {
			for (int j = 0; j < ans1[i].size(); j++) {
				printf("%c", ans1[i][j]);
				if (j != ans1[i].size() - 1)
					printf(" ");
			}
			printf("\n");
		}
		if (ans1.size()==0)
			printf("NO\n");

		if (t)
		printf("\n");

	}
}
