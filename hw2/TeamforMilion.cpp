#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

void countingSort(vector<int>& numbers, int N) {

	int max = *max_element(numbers.begin(), numbers.end());
	int min = *min_element(numbers.begin(), numbers.end());
	int range = max - min + 1;

	vector<int> count(range);
	vector<int> output(N);
	for (int i = 0; i < N; i++) {
		count[numbers[i] - min]++;
	}

	int size = count.size();
	for (int i = 1; i < size; i++) {
		count[i] += count[i - 1];
	}

	for (int i = N - 1; i >= 0; i--) {
		output[count[numbers[i] - min] - 1] = numbers[i];
		count[numbers[i] - min]--;
	}

	for (int i = 0; i < N; i++)
		numbers[i] = output[i];

}
int main() {
	int N;
	cin >> N;
	vector<int> numbers;
	for (int i = 0; i < N; i++) {
		char temp;
		cin >> temp;
		int num = 0;
		if (temp >= 'A' && temp <= 'Z') {
			num = temp - 28;
		}
		if (temp >= 'a' && temp <= 'z') {
			num = temp - 86;
		}
		if (temp >= '0' && temp <= '9') {
			num = temp - 47;
		}
		numbers.push_back(num);
	}
	countingSort(numbers, N);

	vector<char> result(0);
	for (int i = 0; i < N; i++) {
		char a = 0;
		if (numbers[i] >= 37 && numbers[i] <= 62) {
			a = numbers[i] + 28;
		}
		if (numbers[i] >= 11 && numbers[i] <= 36) {
			a = numbers[i] + 86;
		}
		if (numbers[i] >= 1 && numbers[i] <= 10) {
			a = numbers[i] + 47;
		}
		result.push_back(a);
	}

	for (int i = 0; i < N; i++) {
		cout << result[i];
	}
	return 0;
}

