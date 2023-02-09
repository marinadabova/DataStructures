#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& tree, int v) {
	cout << v << " ";
	for (auto x : tree[v]) {
		dfs(tree, x);
	}
}

void bfs(vector<vector<int>>& tree, int v) {
	queue<int> q;
	q.push(v);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		cout << cur << " ";
		for (auto x : tree[cur]) {
			q.push(x);
		}
	}
}
int main() {
	int N, M;
	cin >> N >> M;

	vector<vector<int>> tree(N);
	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		tree[from].push_back(to);
	}


	cout << "DFS traversal: ";
	dfs(tree, 0);

	cout << endl;
	cout << "BFS traversal: ";
	bfs(tree, 0);

	return 0;
}
// 0 ... n
	// m
	 /*7 6
	 0 1
	 0 2
	 1 3
	 1 4
	 1 5
	 2 6*/