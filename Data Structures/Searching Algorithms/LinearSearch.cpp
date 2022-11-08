#include <iostream>
#include <vector>
using namespace std;

int linearSearch(vector<int> v, int length, int x) {
	for (int i = 0; i < length; i++) {
		if (v[i] == x) {
			return i;
		}
	}
	return -1;
}

int main() {

	vector<int> v = { 2, 3, 4, 7, 10, 40, 60 };
					//0  1  2  3   4   5   6
	int x = 4;
	int result = linearSearch(v, v.size(), x);
	cout << result << "\n";

	return 0;
}
