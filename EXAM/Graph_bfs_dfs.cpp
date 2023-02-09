#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& graph, vector<bool>& visited, int node) {
	visited[node] = true;

	for (auto child : graph[node]) {
		if (!visited[child]) {
			dfs(graph, visited, child);
		}
	}

	cout << node << " ";
}
void bfs(vector<vector<int>>& graph, int node) {
	vector<bool> visited(graph.size(), false);
	queue<int> q;
	q.push(node);
	visited[node] = true;

	while (!q.empty()) {
		int currNode = q.front();
		q.pop();
		cout << currNode << " ";

		for (auto x : graph[currNode]) {
			if (!visited[x]) {
				visited[x] = true;
				q.push(x);
			}
		}
	}
}

int main() {
	int nodes, edges;
	cin >> nodes >> edges;
	vector<vector<int>> graph(nodes);

	for (int i = 0; i < edges; ++i) {
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	vector<bool> visited(nodes, false);
	dfs(graph, visited, 0);
	cout << endl;
	bfs(graph, 0);
}