#include <bits/stdc++.h>
using namespace std;


bool sortDescending(const pair<pair<double, double>, int>& a, const pair<pair<double, double>, int>& b) {
	bool flag = false;
	double efficiency1 = a.first.first;
	double efficiency2 = b.first.first;

	double di1 = a.first.second;
	double di2 = b.first.second;

	if (efficiency1 == efficiency2) {
		return di1 > di2;
	}

	return efficiency1 > efficiency2;
}
double calculateEfficiency(const pair<double, double>& a) {
	double efficiency = 0;
	double di = a.first;
	double ti = a.second;
	efficiency = pow((di / 2), 2) / ti;
	return efficiency;
}
int main() {
	long N;
	cin >> N;
	vector<pair<double, double>> vec;

	for (int i = 0; i < N; i++) {
		double di, ti;
		cin >> di >> ti;
		vec.push_back(make_pair(di, ti));
	}
	vector<pair<pair<double, double>, int>> result;

	for (int i = 0; i < N; i++) {
		double efficiency = calculateEfficiency(vec[i]);
		double di = vec[i].first;
		result.push_back(make_pair(make_pair(efficiency, di), i + 1));
	}
	stable_sort(result.begin(), result.end(), sortDescending);

	for (int i = 0; i < N; i++) {
		cout << result[i].second << " ";
	}
	return 0;
}

