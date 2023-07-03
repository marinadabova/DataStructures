//#include <iostream>
//#include <vector>
//using namespace std;
//void selectionSort(vector<int>& array) {
//
//	for (int j = 0; j < array.size() - 1; j++) {
//
//		int positionOfMinElement = j;
//		for (int i = j + 1; i < array.size(); i++) {
//			if (array[i] < array[positionOfMinElement]) {
//				positionOfMinElement = i;
//			}
//		}
//		swap(array[j], array[positionOfMinElement]);
//	}
//
//}
//
//int main() {
//
//	vector<int> v = { 5, 7, 3, 1, 6, 2, 7 };
//
//	selectionSort(v);
//
//	for (int i = 0; i < v.size(); i++) {
//		cout << v[i] << " ";
//	}
//
//	return 0;
//}