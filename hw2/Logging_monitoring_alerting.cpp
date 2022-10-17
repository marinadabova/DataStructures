#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool sortBySec(const pair<long, pair<string, string>>& a, const pair<long, pair<string, string>>& b) {
	bool flag = false;
	string year1(a.second.second.begin() + 6, a.second.second.end());
	string year2(b.second.second.begin() + 6, b.second.second.end());
	if (year1 < year2) {
		flag = year1 < year2;
	}
	if (year1 == year2) {
		string month1(a.second.second.begin() + 3, a.second.second.end() - 5);
		string month2(b.second.second.begin() + 3, b.second.second.end() - 5);
		if (month1 < month2) {
			flag = month1 < month2;

		}
		if (month1 == month2) {
			string day1(a.second.second.begin(), a.second.second.end() - 8);
			string day2(b.second.second.begin(), b.second.second.end() - 8);
			if (day1 < day2) {
				flag = day1 < day2;
			}
			if (day1 == day2) {
				string hh1(a.second.first.begin(), a.second.first.end() - 6);
				string hh2(b.second.first.begin(), b.second.first.end() - 6);
				if (hh1 < hh2) {
					flag = hh1 < hh2;
				}
				if (hh1 == hh2) {
					string min1(a.second.first.begin() + 3, a.second.first.end() - 3);
					string min2(b.second.first.begin() + 3, b.second.first.end() - 3);
					if (min1 < min2) {
						flag = min1 < min2;
					}
					if (min1 == min2) {
						string sek1(a.second.first.begin() + 6, a.second.first.end());
						string sek2(b.second.first.begin() + 6, b.second.first.end());
						if (sek1 < sek2) {
							flag = sek1 < sek2;
						}
					}
				}
			}
		}
	}
	return flag;
}
int main() {
	long N;
	cin >> N;
	vector<pair<long, pair<string, string>>> timestamp;


	for (int i = 1; i <= N; i++) {
		string hours, date;
		cin >> hours >> date;
		timestamp.push_back(make_pair(i, make_pair(hours, date)));
	}
	stable_sort(timestamp.begin(), timestamp.end(), sortBySec);

	for (int i = 0; i < N; i++) {

		cout << timestamp[i].first << endl;

	}
	return 0;
}