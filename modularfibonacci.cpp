#include <bits/stdc++.h>
using namespace std;
const int size = 2;
long long n;
int mod;
struct matrix {
	int mat[size][size];
};
matrix mul(const matrix &a, const matrix &b) {
	matrix res;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++) {
			res.mat[i][j] = 0;
			for (int k = 0; k < size; k++) {
				long long tmp = a.mat[i][k] * 1LL * b.mat[k][j];
				tmp %= mod;
				res.mat[i][j] += tmp;
				if (res.mat[i][j] >= mod)
					res.mat[i][j] -= mod;
			}
		}
	return res;
}
matrix ident() {
	matrix res;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			res.mat[i][j] = (i == j);
	return res;
}
matrix power(matrix a, long long p) {
	matrix res = ident();
	while (p) {
		if (p & 1)
			res = mul(a, res);
		a = mul(a, a);
		p >>= 1;
	}
	return res;
}
int main() {
	while (cin >> n >> mod) {
		mod = 1 << mod;
		matrix a = { 0, 1, 1, 1 };
		matrix b = { 0, 0, 1, 0 };
		a = power(a, n);
		b = mul(a, b);
		cout << b.mat[0][0] << endl;
	}
}
