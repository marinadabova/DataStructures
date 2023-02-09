#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& graph, vector<bool>& visited, int node) {
	if (!visited[node]) {
		visited[node] = true;
		for (int child : graph[node]) {
			dfs(graph, visited, child);
		}
	}
}

int findNumberOfConnectedComponents(vector<vector<int>>& graph) {
	int count = 0;
	int grSize = graph.size();
	vector<bool> visited(grSize);
	for (int i = 0; i < grSize; i++) {
		if (!visited[i]) {
			dfs(graph, visited, i);
			count++;
		}
	}

	return count;
}

int main() {

	int brV, brEdg;
	cin >> brV >> brEdg;
	vector<vector<int>> graph(brV);
	for (int j = 0; j < brEdg; j++) {
		int edgStart, edgEnd;
		cin >> edgStart >> edgEnd;

		graph[edgStart].push_back(edgEnd);
		graph[edgEnd].push_back(edgStart);
	}
	cout << findNumberOfConnectedComponents(graph) << " ";

	return 0;
}
