#include <bits/stdc++.h>
#include <string.h>
using namespace std;
bool g[105][105];
int convert(string s) {
	stringstream ss(s);
	int x;
	ss >> x;
	return x;
}
int main() {
	int t;
	scanf("%d ", &t);
	while (t--) {
		memset(g, false, sizeof(g));
		char blank[200];
		int p, t;
		scanf("%d %d ", &p, &t);
		string s;
		int a, b;
		while (gets(blank)) {
			if (strcmp(blank, "") == 0)
				break;
			sscanf(blank, "%d %d", &a, &b);
			g[a][b] = true;
		}
		int ans = 0;
		for (int i = 1; i <= p; i++) {
			bool fnd = false;
			for (int j = i + 1; j <= p; j++) {
				bool finish = true;
				for (int k = 1; k <= t; k++)
					if (g[i][k] != g[j][k]) {
						finish = false;
						break;
					}
				if (finish)
					fnd = true;
			}
			if (!fnd)
				ans++;
		}
		printf("%d\n", ans);
		if(t)	puts("");
	}
}
