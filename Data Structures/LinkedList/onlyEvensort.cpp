#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

std::vector<int> sortEvenNumbers(const std::vector<int>& arr) {
	std::unordered_map<int, int> evenNumberMap;
	for (int num : arr) {
		if (num % 2 == 0 && num >= 0 && num <= 10) {
			evenNumberMap[num]++;
		}
	}

	std::vector<int> sortedArr = arr;
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
	std::vector<int> originalArray = { 5, 2, 9, 10, 0, 8, 7 };
	std::vector<int> sortedResult = sortEvenNumbers(originalArray);

	for (int num : sortedResult) {
		std::cout << num << " ";
	}
	std::cout << std::endl;

	return 0;
}
