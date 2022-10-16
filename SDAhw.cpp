#include <bits/stdc++.h>
using namespace std;

bool sortFunc(const pair<string, long long>& a, const pair<string, long long>& b) {

	long long points1 = a.second;
	long long points2 = b.second;

	string name1 = a.first;
	string name2 = b.first;

	if (points1 == points2) {
		return name1 < name2;
	}
	return points1 > points2;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long N;
	cin >> N;
	vector<string>names;
	for (int i = 0; i < N; i++) {
		string name;
		cin >> name;
		names.push_back(name);
	}
	vector<long long>points;
	for (int i = 0; i < N; i++) {
		long long point;
		cin >> point;
		points.push_back(point);
	}

	vector<pair<string, long long>> v;
	for (int i = 0; i < N; i++) {
		v.push_back(make_pair(names[i], points[i]));
	}

	stable_sort(v.begin(), v.end(), sortFunc);
	for (int i = 0; i < N; i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}
	return 0;
}