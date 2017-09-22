#include <bits/stdc++.h>
using namespace std;
vector<string> vec;
vector<int> graph[26];
int indeg[26];
int in[26];
string toposort() {
	string ans = "";
	queue<int> q;
	for (int i = 0; i < 26; i++)
		if (indeg[i] == 0 && in[i] == 1)
			q.push(i);
	while (!q.empty()) {
		int cur = q.front();
		ans += cur + 'A';
		q.pop();
		for (int i = 0; i < graph[cur].size(); i++) {
			int child = graph[cur][i];
			indeg[child]--;
			if (indeg[child] == 0)
				q.push(child);
		}
	}
	return ans;
}
int main() {
	string s;
	while (cin >> s) {
		memset(indeg, 0, sizeof(indeg));
		memset(in, 0, sizeof(indeg));

		vec.clear();
		while (s != "#") {
			vec.push_back(s);
			cin >> s;
		}
		for (int i = 1; i < vec.size(); i++) {
			string s1 = vec[i - 1];
			string s2 = vec[i];
			int cnt = 0;
			while (cnt < s1.size() && cnt < s2.size()) {
				if (s1[cnt] != s2[cnt]) {
					indeg[s2[cnt] - 'A']++;
					graph[s1[cnt] - 'A'].push_back(s2[cnt] - 'A');
					in[s1[cnt] - 'A'] = 1;
					in[s2[cnt] - 'A'] = 1;
					break;
				} else
					cnt++;
			}
		}
		cout << toposort() << endl;
		for (int i = 0; i < 26; i++)
			graph[i].clear();
	}
}
