#include <bits/stdc++.h>
using namespace std;
//Намерете дължината на минималния път от върх с номер 1 до върх с номер N
//и броя различни начини, по които може да бъде постигнат.

vector<vector<pair<long, long>>> adj(100001);
long distSize = adj.size();
vector<pair<long, long>> dist(distSize);

void dijkstra(long v) {
	long size = adj.size();

	for (int i = 0; i < size; i++) {
		dist[i].first = LONG_MAX;
		dist[i].second = 0;
	}
	dist[v].first = 0;
	dist[v].second = 1;

	priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> pq;
	pq.push({ 0,v });

	while (!pq.empty()) {
		long cur = pq.top().second;
		long curW = pq.top().first;
		pq.pop();

		for (auto x : adj[cur]) {
			long child = x.first;
			long childW = x.second;
			long distance = curW + childW;

			if (dist[child].first > distance) {
				dist[child].first = distance;
				dist[child].second = dist[cur].second;

				pq.push({ distance,child });
			}
			else if (dist[child].first == distance) {
				dist[child].second = (dist[child].second + dist[cur].second) % 1000000007;

			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		long u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({ v,c });
	}
	dijkstra(1);
	if (dist[N].second) {
		cout << dist[N].first << " " << dist[N].second;
	}
	else {
		cout << -1 << " " << 0;
	}
	return 0;
}
