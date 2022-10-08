#include <bits/stdc++.h>
using namespace std;


int main() {
	long Q;
	cin >> Q;
	long len;
	vector<pair<long, string>> v;
	long temp = Q;
	while (temp--) {
		string list;
		cin >> len >> list;
		v.push_back(make_pair(len,list));
	}

	vector<long>result;
	for (int i = 0; i < Q; i++) {
		long N = v[i].first;
		long minDel = 0;
		for (int j = 1; j <= N; j++) {
			if (v[i].second[j - 1] == v[i].second[j]) {
				minDel++;
			}
			else {
				continue;
			}
		}
		result.push_back(minDel);
	}
	
	int size = result.size();
	for (int i = 0; i < size; i++) {
		cout << result[i] << endl;
	}
	return 0;
}

