#include <bits/stdc++.h>
using namespace std;

int main() {
    long N = 0;
    cin >> N;

    vector<long> v;
    vector<long> counter(100000);
    for (int i = 0; i < N; i++) {
        long num;
        cin >> num;
        v.push_back(num);
        counter[v[i]]++;

    }
    long size = counter.size();

    for (int i = 0; i < size; i++) {
        if (counter[i] >= 1) {
            cout << i << " ";

        }
    }

    return 0;
}