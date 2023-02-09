#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;


vector<int> path;
unordered_set<int> locked;


void bfs(int from, vector<vector<int>>& graph, vector<int>& dist) {
	dist[from]++;
	queue<int> q;
	q.push(from);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (auto x : graph[cur]) {
			if (!locked.count(x) && !dist[x]) {
				dist[x] = dist[cur] + 1;
				q.push(x);
			}
		}

	}

}

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> graph(N);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}
	int K;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int num;
		cin >> num;
		path.push_back(num);
		locked.insert(num);

	}
	int from, to;
	from = path[0]; //0
	locked.erase(from); //4 1

	vector<int> dist(N);

	int ans = 0;
	for (int i = 1; i < K; i++) {

		for (int j = 0; j < N; j++) {
			dist[j] = 0;
		}

		to = path[i];
		locked.erase(to);

		bfs(from, graph, dist);

		ans += dist[to] - 1;
		if (!dist[to]) {
			cout << "-1";
			return 0;
		}
		from = to;
	}
	cout << ans;
	return 0;
}
