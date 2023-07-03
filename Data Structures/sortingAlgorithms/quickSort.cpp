#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int partition(vector<int>& array, int left, int right) { // [left, right]

	int pivot = array[right];  // pick rightmost element as pivot from the array

	int positonOfPivot = left; // This will be final/correct position of the pivot. 
	//positonOfPivot = left -> We allow that all elements of array are bigger than pivot

	 //elements less than pivot will be pushed to the left of positonOfPivot
	 //elements more than pivot will be pushed to the right of positonOfPivot
	while (left < right){
		if (array[left] < pivot) {
			swap(array[positonOfPivot++], array[left]);
		}
		left++;
	}

	swap(array[positonOfPivot], array[right]);
	return positonOfPivot;
}

void quickSort(vector<int>& array, int left, int right) {

	if (left >= right) {
		return;
	}

	int pivot = partition(array, left, right);

	quickSort(array, left, pivot - 1);

	quickSort(array, pivot + 1, right);

}


int main() {

	vector<int> v = { 7, 4, -2, 1, 6, 5, 0, -4, 2 };

	quickSort(v, 0, v.size() - 1);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	return 0;
}
