#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long N, Q;
	cin >> N >> Q;
	vector<long long> weight;
	for (int i = 0; i < N; i++) {
		long long w;
		cin >> w;
		weight.push_back(w);
	}
	vector<pair<long long, long long>> tournaments;
	for (int i = 0; i < Q; i++) {
		long long minW, maxW;
		cin >> minW >> maxW;
		tournaments.push_back(make_pair(minW, maxW));

	}
	sort(weight.begin(), weight.end());
	vector <long long>result;
	for (int i = 0; i < Q; i++) {
		if (tournaments[i].first > tournaments[i].second) {
			result.push_back(0);
		}
		else {
			auto minj = lower_bound(weight.begin(), weight.end(), tournaments[i].first);
			long long index1 = minj - weight.begin();

			auto maxj = upper_bound(weight.begin(), weight.end(), tournaments[i].second);
			long long index2 = maxj - weight.begin() - 1;

			long long counter = (index2 - index1) + 1;
			result.push_back(counter);
		}

	}
	for (int i = 0; i < Q; i++) {
		cout << result[i] << "\n";
	}
	return 0;
}