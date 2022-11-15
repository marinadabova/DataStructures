#include <bits/stdc++.h>
using namespace std;

int main() {
	long N;
	cin >> N;
	vector<long> vec;
	for (int i = 0; i < N; i++) {
		long people;
		cin >> people;
		vec.push_back(people);
	}
	stack<long> inteligence;
	inteligence.push(vec[0]);

	for (int i = 1; i < N; i++) {
		if (vec[i] < 0) {
			if (inteligence.top() < 0) {
				inteligence.push(vec[i]);
			}

			else if (inteligence.top() > 0) {

				if (inteligence.top() > abs(vec[i])) {
					continue;
				}
				else if (inteligence.top() == abs(vec[i])) {
					inteligence.pop();
					continue;
				}
				else if (inteligence.top() < abs(vec[i])) {
					while (inteligence.top() < abs(vec[i]) && inteligence.empty() == false) {
						if (inteligence.top() < 0) {
							break;
						}
						inteligence.pop();
						if (inteligence.empty() == true) {
							break;
						}

					}
					if (!inteligence.empty() && inteligence.top() > abs(vec[i])) {
						continue;

					}
					else if (!inteligence.empty() && inteligence.top() == abs(vec[i])) {
						inteligence.pop();
						continue;
					}
					else {
						inteligence.push(vec[i]);
					}
				}
			}
		}
		else if (vec[i] > 0) {
			inteligence.push(vec[i]);
		}
	}

	stack<long> result;
	while (!inteligence.empty()) {
		result.push(inteligence.top());
		inteligence.pop();
	}
	while (!result.empty()) {
		cout << result.top() << " ";
		result.pop();
	}
	return 0;
}