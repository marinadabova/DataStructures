#include <bits/stdc++.h>
using namespace std;

long ternarySearch(long x, long left, long right,long depth) {
	if (right < left) {
		return 0;
	}
	long  mid1 = (2 * left + right + 1) / 3;
	long  mid2 = (left + 2 * right + 1) / 3;

	if (mid1 > x) {
		return ternarySearch(x, left, mid1 - 1, depth + 1);
	}
	if (mid2 < x) {
		return ternarySearch(x, mid2 + 1, right, depth + 1);
	}
	return depth;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	long P, N;
	cin >> P >> N;

	vector<long> bonbons;
	long right = pow(3, P);
	for (int i = 0; i < N; i++) {
		long fr;
		cin >> fr;
		bonbons.push_back(ternarySearch(fr, 1, right, 1));
	}
	for (int i = 0; i < N; i++) {
		cout << bonbons[i] << endl;
	}
	return 0;
}
