#include <iostream>
#include <vector>
using namespace std;

//Iterative method
int binarySearch(vector<int> v, int start, int end, int x){
	while (end >= start){

		int m = start + (end - start) / 2; //Find middle element
		if (v[m] == x) {
			return m;
		}
		if (x < v[m]) { // If x is smaller, ignore right half
			end = m - 1;
		}
		else {  
			start = m + 1; // If x greater, ignore left half
		}
	}

	return -1;
}

//Recursive method
int binarySearchRec(vector<int> v, int start, int end, int x){
	while (end >= start) {
		int mid = start + (end - start) / 2; //Find middle element

		if (v[mid] == x) {
			return mid;
		}
		if (v[mid] > x){  // If element is smaller than mid, then it is in the left subarray
			return binarySearchRec(v, start, mid - 1, x);
		}
		return binarySearchRec(v, mid + 1, end, x); // Else the element is in the right subarray
	}
	return -1;
}

int main(){

	vector<int> v = { 2, 3, 4, 7, 10, 40, 60 };
					//0  1  2  3   4   5   6
	int x = 4;
	int result = binarySearch(v, 0, v.size() - 1, x);
	cout << result << "\n";

	int result2 = binarySearchRec(v, 0, v.size() - 1, x);
	cout << result2 << "\n";

	return 0;
}
