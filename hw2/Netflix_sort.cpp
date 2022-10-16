#include <bits/stdc++.h>
using namespace std;

int counter[123];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string S;
	cin >> S;

	int size = S.length();
	for (int i = 0; i < size; i++) {
		if (S[i] >= 'a' && S[i] <= 'z') {
			counter[S[i]]++;
		}
		else if (S[i] >= 'A' && S[i] <= 'Z') {

			counter[S[i]]++;
		}
		else {

			counter[S[i]]++;
		}
	}
	vector<int> v;
	int n = v.size();
	for (int i = 48; i < 123; i++) {
		if (counter[i] == 1) {
			char ch = (char)i;
			size_t found = S.find(ch);
			v.push_back(found);
			n++;
		}
		
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}

	return 0;
}
