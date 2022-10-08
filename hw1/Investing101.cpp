#include <bits/stdc++.h>
using namespace std;


int main() {
	long N;
	cin >> N;

	vector<long> v(100000);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	long bought=0;
	int j = 0;
	long profit = 0;
	for (int i = 0; i < N; i++) {
		long sold = 0;
		if (v[i] < v[i + 1]) {
			for(j=i+1;v[j]>sold;j++){
				sold = v[j];
				bought = v[i];
			}
			profit += sold - bought;
			j--;
			i = j;
		}

	}
	cout << profit;


	return 0;
}