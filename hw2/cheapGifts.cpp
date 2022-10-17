#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int partition(vector<int>& possibleGiftPrice, int l, int r) {

	int pivot = possibleGiftPrice[r];
	int i = l;

	for (int j = l; j < r; j++) {
		if (possibleGiftPrice[j] <= pivot) {
			swap(possibleGiftPrice[i], possibleGiftPrice[j]);
			i++;
		}
	}
	swap(possibleGiftPrice[i], possibleGiftPrice[r]);
	return i;
}

void quick_sort(vector<int>& possibleGiftPrice, int l, int r) {
	if (l < r) {
		int pivot = partition(possibleGiftPrice, l, r);

		quick_sort(possibleGiftPrice, l, pivot - 1);
		quick_sort(possibleGiftPrice, pivot + 1, r);
	}
}
int main() {
	int N;
	cin >> N;
	vector<int> possibleGiftPrice;
	for (int i = 0; i < N; i++) {
		int price;
		cin >> price;
		possibleGiftPrice.push_back(price);
	}
	int K;
	cin >> K;
	long long minPriceSum = 0;


	quick_sort(possibleGiftPrice, 0, N - 1);

	for (int i = 0; i < K; i++) {
		minPriceSum += possibleGiftPrice[i];
	}

	cout << minPriceSum;    
	return 0;
}
