#include <bits/stdc++.h>
using namespace std;

bool checkIfOdd(long i) {
	return (i % 2) == 1;
}
int main() {
	long N;
	cin >> N;
	vector <long> bets;

	for (int i = 0; i < N; i++) {
		long bet;
		cin >> bet;
		bets.push_back(bet);
	}

	vector <long> result;

	vector<long>::iterator bound;
	bound = stable_partition(bets.begin(), bets.end(), checkIfOdd);

	for (vector<long>::iterator it = bound; it != bets.end(); it++) {
		result.push_back(*it);
	}

	for (vector<long>::iterator it = bets.begin(); it != bound; it++) {
		result.push_back(*it);
	}

	for (int i = 0; i < N; i++) {
		cout << result[i] << "\n";
	}


	return 0;
}
