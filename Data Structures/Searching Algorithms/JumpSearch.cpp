#include<iostream>
#include <cmath>
#include <vector>

using namespace std;

void jump_search(vector<int> v, int key){
	int len = v.size();
	int jump = sqrt(len);
	int start = 0;
	int end = start + jump;

	
	while (end < len && v[end] <= key){ // get the correct block to search
		start = end;
		end += jump;

		if (end > len - 1)
			end = len;
	}

	for (int i = start; i < end; i++){ 	// now do a linear search in the block
		if (v[i] == key){
			cout << " The key is present in the array, pos=" << i << endl;
			return;
		}

	}
	cout << " The key is NOT in the array" << endl;
}


int main(){
	vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
	int key = 14;

	jump_search(v, key);

	return 0;
}