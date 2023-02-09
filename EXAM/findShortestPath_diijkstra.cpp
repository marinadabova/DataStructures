#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<long, long>>> adj(100001);
long adjSize = adj.size();
vector<long> dist(adjSize);

void dijkstra(long v) {
	long size = adj.size();

	for (int i = 0; i < size; i++) {
		dist[i] = LONG_MAX;
	}
	dist[v] = 0;

	priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> pq;
	pq.push({ 0,v });
	while (!pq.empty()) {
		long cur = pq.top().second;
		long curW = pq.top().first;
		pq.pop();

		if (curW > dist[cur])
			continue;

		for (auto x : adj[cur]) {
			long child = x.first;
			long childW = x.second;
			long temp = curW + childW;
			if (dist[child] > temp) {
				dist[child] = temp;
				pq.push({ temp,child });
			}
		}
	}
}
int main() {
	long N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		long u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ v,w });
		adj[v].push_back({ u,w });

	}
	long s;
	cin >> s;
	dijkstra(s);

	for (int i = 1; i <= N; i++) {
		if (i != s) {
			if (dist[i] == LONG_MAX) {
				cout << "-1" << " ";
			}

			else {
				cout << dist[i] << " ";
			}
		}
	}

	return 0;
}
