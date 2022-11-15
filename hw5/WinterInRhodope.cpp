#include <bits/stdc++.h>
using namespace std;

int main() {
	long N, M, T;
	cin >> N >> M >> T;

	vector<vector<long>> apples(N);
	for (int i = 0; i < N; i++) {
		apples[i] = vector<long>(M);
	}

	long allApples = N * M;
	queue<pair<long, long>> q;

	long row, col;
	while (cin >> row >> col) {
		apples[N - row][col - 1] = 1;
		q.push(make_pair(N - row, col - 1));
	}

	long days = 0;
	long rottenApples = q.size();

	for (int i = T; T > 0; T--) {
		days++;
		for (int j = q.size(); j > 0; j--) {
			pair<long, long> place = q.front();
			q.pop();
			if (place.first + 1 < N && apples[place.first + 1][place.second] == 0) {
				rottenApples++;
				apples[place.first + 1][place.second] = days;
				q.push({ place.first + 1, place.second });
			}
			if (place.second + 1 < M && apples[place.first][place.second + 1] == 0) {
				rottenApples++;
				apples[place.first][place.second + 1] = days;
				q.push({ place.first, place.second + 1 });
			}

			if (place.first - 1 >= 0 && apples[place.first - 1][place.second] == 0) {
				rottenApples++;
				apples[place.first - 1][place.second] = days;
				q.push({ place.first - 1, place.second });
			}

			if (place.second - 1 >= 0 && apples[place.first][place.second - 1] == 0) {
				rottenApples++;
				apples[place.first][place.second - 1] = days;
				q.push({ place.first, place.second - 1 });
			}

		}
	}
	cout << allApples - rottenApples;

	return 0;
}
