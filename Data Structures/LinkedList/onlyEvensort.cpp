#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

vector<int> sortEvenNumbers(const vector<int>& arr) {
	unordered_map<int, int> evenNumberMap;
	for (int num : arr) {
		if (num % 2 == 0 && num >= 0 && num <= 10) {
			evenNumberMap[num]++;
		}
	}

	vector<int> sortedArr = arr;
	int evenIndex = 0;


	for (int i = 0; i < sortedArr.size(); ++i) {
		if (sortedArr[i] % 2 == 0 && sortedArr[i] >= 0 && sortedArr[i] <= 10) {
			while (evenNumberMap[evenIndex] == 0) {
				evenIndex++;
			}
			sortedArr[i] = evenIndex;
			evenNumberMap[evenIndex]--;
		}
	}

	return sortedArr;
}

int main() {
	vector<int> originalArray = { 5, 2, 9, 10, 0, 8, 7 };
	vector<int> sortedResult = sortEvenNumbers(originalArray);

	for (int num : sortedResult) {
		cout << num << " ";
	}
	cout << std::endl;

	return 0;
}
