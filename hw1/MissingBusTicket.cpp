#include <bits/stdc++.h>
using namespace std;

int findMissingBusTicket(vector<long>& tickets, long N) {
	int missingTicket = N + 1;

	for (int i = 0; i < N; i++) {
		if (tickets[i] > 0 && tickets[i] <= N) {

			if (tickets[i] != i + 1 && tickets[tickets[i] - 1] != tickets[i]) {
				swap(tickets[i], tickets[tickets[i] - 1]);
				i--;
			}
		}
		else
			continue;
	}

	for (int i = 0; i < N; i++) {
		if (tickets[i] != i + 1) {
			missingTicket = i + 1;
			return missingTicket;
		}

	}
	return missingTicket;

}


int main() {
	long N;
	cin >> N;
	vector<long> tickets;

	for (int i = 0; i < N; i++) {
		long T;
		cin >> T;
		tickets.push_back(T);
	}

	cout << findMissingBusTicket(tickets, N);

	return 0;
}