//#include <bits/stdc++.h>
//using namespace std;
//const int N = 100001;
//vector<int>tree[N];
//void dfs(int v) {
//	cout << v << " ";
//	for (int i = 0; i < tree[v].size(); i++) {
//		dfs(tree[v][i]);
//	 }
//	//for (auto i : tree[v]) {
//	//	dfs(i);
//	//}
//
//	
//}
//void bfs(int v) {
//	queue<int> q;
//	q.push(v);
//
//	while (!q.empty()) {
//		int cur = q.front();
//		q.pop();
//		cout << cur << " ";
//
//		for (int i = 0; i < tree[cur].size(); i++) {
//			q.push(tree[cur][i]);
//		}
//	}
//}
//
//
//
//int main() {
//	int n;
//	cin >> n;
//	int temp = n;
//	while (temp--) {
//		int from, to;
//		cin >> from >> to;
//		tree[from].push_back(to);
//	}
//	bfs(0);
//	cout << endl;
//	dfs(0);
//	return 0;
//}