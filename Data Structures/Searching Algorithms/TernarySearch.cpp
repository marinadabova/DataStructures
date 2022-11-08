#include <iostream>
#include <vector>
using namespace std;

int ternarySearch(vector<int> v, int start, int end, int key){
	if (end >= start) {
		
		int mid1 = start + (end - start) / 3; // Find mid1 and mid2
		int mid2 = end - (end - start) / 3;


		if (v[mid1] == key) {		// Check if key is present at  mid1
			return mid1;
		}
		if (v[mid2] == key) { // Check if key is present at  mid2
			return mid2;
		}

		if (key < v[mid1]) {                 //If the key is smaller than mid1,than the key lies between start and mid1
			return ternarySearch(v, start, mid1 - 1, key);
		}

		else if (key > v[mid2]) {           //If the key is greater than mid2q than the key lies between mid2 and end
			return ternarySearch(v, mid2 + 1, end, key);
		}
		else {								//Else -the key is between mid1 and mid2
			return ternarySearch(v, mid1 + 1, mid2 - 1, key);
		}
	}

	return -1;
}

int main(){
					  //0  1  2  3  4  5  6  7  8  9
	vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int key = 6;
	int ans = ternarySearch(v, 0, v.size() - 1, key);

	cout << "Index of " << 6 << " is " << ans << endl;

}
