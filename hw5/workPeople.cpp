#include <bits/stdc++.h>
using namespace std;
/*
10 4
1 3 9 5 2 7 4 11 5 6
*/

class Queue {
private:
	list<long> data;
public:
	bool isEmpty() {
		return data.empty();
	}
	void push(long num) {
		data.push_back(num);
	}

	void popFront() {
		if (isEmpty()) {
			return;
		}
		else {
			data.pop_front();
		}
	}
	long peekFront() {
		if (isEmpty()) {
			return -1;
		}
		else {
			return data.front();
		}
	}

	void popBack() {
		if (isEmpty()) {
			return;
		}
		else {
			data.pop_back();
		}
	}
	long peekBack() {
		if (isEmpty()) {
			return -1;
		}
		else {
			return data.back();
		}
	}
};

long long minSumFunc(vector<long>& lazy, long N, long K) {

	long long sumMin = 0;
	Queue windowK;

	for (int i = 0; i < K; i++) {

		while (!windowK.isEmpty() && lazy[i] <= lazy[windowK.peekBack()]) {
			long temp = lazy[windowK.peekBack()];
			windowK.popBack();
		}
		windowK.push(i);
	}

	for (int i = K; i < N; i++) {
		long tem = windowK.peekFront();
		long temp = lazy[windowK.peekFront()];
		sumMin += lazy[windowK.peekFront()];

		long diff = i - K;
		while (!windowK.isEmpty() && diff >= windowK.peekFront()) {
			windowK.popFront();
		}
		while ((!windowK.isEmpty()) && lazy[i] <= lazy[windowK.peekBack()]) {
			windowK.popBack();
		}
		windowK.push(i);
	}
	long temp = lazy[windowK.peekFront()];
	sumMin += lazy[windowK.peekFront()];

	return sumMin;
}


int main() {
	long N, K;
	cin >> N >> K;

	vector<long> lazy;
	for (int i = 0; i < N; i++) {
		long num;
		cin >> num;
		lazy.push_back(num);
	}
	cout << minSumFunc(lazy, N, K);

	return 0;
}