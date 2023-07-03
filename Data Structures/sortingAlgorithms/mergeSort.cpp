#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void mergeTwoSortedArrays(vector<int>& array, int left, int middle, int right) {

	vector<int> leftArray, rightArray;

	int l = left;
	while (l <= right) {

		if (l <= middle) {
			leftArray.push_back(array[l]);
		}

		else { // l > middle
			rightArray.push_back(array[l]);
		}

		l++;
	}

	int leftIndex = 0, rightIndex = 0;
	while (leftIndex < leftArray.size() && rightIndex < rightArray.size()) {
		if (leftArray[leftIndex] > rightArray[rightIndex]) {
			array[left++] = rightArray[rightIndex++];
		}

		else {
			array[left++] = leftArray[leftIndex++];
		}
	}

	while (leftIndex < leftArray.size()){
		array[left++] = leftArray[leftIndex++];
	}

	while (rightIndex < rightArray.size()){
		array[left++] = rightArray[rightIndex++];
	}

}

void mergeSort(vector<int>& array, int left, int right) {

	if (left >= right) {
		return;
	}

	int middle = left + (right - left) / 2;

	mergeSort(array, left, middle);
	mergeSort(array, middle + 1, right);

	mergeTwoSortedArrays(array, left, middle, right);

}
int main() {

	vector<int> v = { 38, 27, 43, 3, 9, 82, 10 };

	mergeSort(v, 0, v.size() - 1);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	return 0;
}
