#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main() {

	int target = 8;

	vector<int> vect1 = { 5, 7, 7, 8, 8, 8, 10 };
					    //0  1  2  3  4  5  6
	auto lower = lower_bound(vect1.begin(), vect1.end(), target);
	int startIndex = lower - vect1.begin(); //3

	auto upper = upper_bound(vect1.begin(), vect1.end(), target);
	int endIndex = (upper - vect1.begin()) - 1; //5

	if (vect1[endIndex] == target && vect1[startIndex] == target)
		cout << "[" << startIndex << "," << endIndex << "]";

	else
		cout << "[" << -1 << "," << -1 << "]";



	vector<int> vect = { 1,4,4,4,5,5,5,5 };
				/*		0 1 2 3 4 5 6 7 
						1 2 3 4 5 6 7 8*/

	auto first_4 = find(vect.begin(), vect.end(), 4);  // Iterator to the first occurrence of 4  //n slojnost

	bool found_4 = binary_search(vect.begin(), vect.end(), 4);  // True if 4 exists in the sorted collection
	/*binary_search vrushta true ili false
	ako iskame da vurne index-a na elementa to -> upper_bound ili lower_bound

	lower_bound ->kude se namira,adresa na 1viq element,koito ima stoinost ne po-malka ot tursenata stoinost
	upper_bound ->kude se namira,adresa na 1viq element,koito ima stoinost po-golqma ot tursenata stoinost*/

	vector<int>::iterator a = vect.begin();
	int b = *a;

	vector<int>::iterator upper1, upper2, upper3, upper4, upper5;
	upper1 = upper_bound(vect.begin(), vect.end(), 6); // Iterator to the first element > 6 
	upper2 = upper_bound(vect.begin(), vect.end(), 0); // Iterator to the first element > 0
	upper3 = upper_bound(vect.begin(), vect.end(), 4); // Iterator to the first element > 4
	upper4 = upper_bound(vect.begin(), vect.end(), 3); // Iterator to the first element > 3
	upper5 = upper_bound(vect.begin(), vect.end(), 2);

	int IndexUpper1 = (upper1 - vect.begin());
	int IndexUpper2 = (upper2 - vect.begin());
	int IndexUpper3 = (upper3 - vect.begin());
	int IndexUpper4 = (upper4 - vect.begin());
	int IndexUpper5 = (upper5 - vect.begin());

	/*                 { 1,4,4,4,5,5,5,5};
					   0 1 2 3 4 5 6 7
					   1 2 3 4 5 6 7 8*/

	vector<int>::iterator low1 = lower_bound(vect.begin(), vect.end(), 6); // Iterator to the first element >= 6
	vector<int>::iterator low2 = lower_bound(vect.begin(), vect.end(), 0); // Iterator to the first element >= 0
	auto low3 = lower_bound(vect.begin(), vect.end(), 4); // Iterator to the first element >= 4
	auto low4 = lower_bound(vect.begin(), vect.end(), 3); // Iterator to the first element >= 3

	auto x = 2;  //int
	auto xx = 2.5;  //double
	auto xxx = "abc";  //str/char
	auto y = { 1,2 };

	int startIndex1 = low1 - vect.begin();
	int startIndex2 = low2 - vect.begin();
	int startIndex3 = low3 - vect.begin();
	int startIndex4 = low4 - vect.begin();


	cout << startIndex1 << " " << startIndex2 << " " << startIndex3 << " " << startIndex4 << "\n";
}