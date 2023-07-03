#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& array) {
	for (int i = 0; i < array.size(); i++) {
		int curEl = array[i];
		int j = i;
		while (j > 0 && curEl < array[j - 1]) {
			array[j] = array[j - 1];
			j--;
		}
		array[j] = curEl;
	}
	

}
int main() {

	vector<int> v = { 5, 7, 3, 1, 6, 2, 7 };

	insertionSort(v);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	return 0;
}
