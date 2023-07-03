#include <iostream>
#include <vector>
using namespace std;
void bubbleSort(vector<int>& array) {

	for (int i = 0; i < array.size() - 1; i++){
		bool atLeastOneSwap = false;

		for (int j = 0; j < array.size() - i - 1; j++){
			if (array[j] > array[j + 1]) {
				swap(array[j], array[j + 1]);
				atLeastOneSwap = true;
			}
		}

		if (!atLeastOneSwap) {
			break;
		}

	}

}
int main() {

	vector<int> v = { 5, 7, 3, 1, 6, 2, 7 };

	bubbleSort(v);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	return 0;
}
