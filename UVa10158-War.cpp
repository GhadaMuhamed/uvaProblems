#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int par[10005];
int war[10005];
int dsu(int v) {
	return (par[v] == v) ? v : dsu(par[v]);
}
bool isSameSet(int x, int y) {
	if (dsu(x) == dsu(y))
		return true;
	return false;
}
void Union(int x, int y) {
	if (isSameSet(x, y))
		return;
	x = dsu(x);
	y = dsu(y);
	int warx = war[x] > -1 ? dsu(war[x]) : -1;
	int wary = war[y] > -1 ? dsu(war[y]) : -1;
	if (warx > -1 && wary > -1) {
		int tmp1 = dsu(warx);
		int tmp2 = dsu(wary);
		if (tmp1 < tmp2)
			par[tmp2] = tmp1;
		else
			par[tmp1] = tmp2;
	}

	if (warx < wary && warx != -1)
		war[wary] = warx;
	else if (wary < warx && wary != -1)
		war[warx] = wary;
	else if (warx == -1)
		war[x] = wary;
	else if (wary == -1)
		war[y] = warx;
	if (x < y)
		par[y] = x;
	else
		par[x] = y;

}
void makeEnemy(int x, int y) {
	x = dsu(x);
	y = dsu(y);
	if (war[y] > -1)
		Union(x, war[y]);
	if (war[x] > -1)
		Union(y, war[x]);
	int warx = war[x] > -1 ? dsu(war[x]) : -1;
	int wary = war[y] > -1 ? dsu(war[y]) : -1;
	if (warx == -1 && wary == -1)
		war[x] = y, war[y] = x;
	else if (warx == -1)
		war[x] = wary;
	else if (wary == -1)
		war[y] = warx;

}
bool areEnemies(int x, int y) {
	x = dsu(x);
	y = dsu(y);
	if (war[x] == -1 || war[y] == -1)
		return false;
	war[x] = dsu(war[x]);
	war[y] = dsu(war[y]);

	return (war[x] == y || war[y] == x);
}
int main() {
	int n;
	cin >> n;
	int a, b, c;
	cin >> a >> b >> c;
	for (int i = 0; i < n; i++)
		par[i] = i, war[i] = -1;
	while (a || b || c) {
		if (a == 1) {
			if (areEnemies(b, c))
				cout << -1 << endl;
			else
				Union(b, c);
		} else if (a == 2) {
			if (isSameSet(b, c))
				cout << -1 << endl;
			else
				makeEnemy(b, c);
		} else if (a == 3)
			cout << isSameSet(b, c) << endl;
		else
			cout << areEnemies(b, c) << endl;
		cin >> a >> b >> c;
	}
}
