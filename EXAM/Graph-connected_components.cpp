#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& graph, vector<bool>& visited, map<int, vector<int>>& mp, int node, int component) {

	visited[node] = true;
	mp[component].push_back(node);

	for (auto x : graph[node]) {
		if (!visited[x]) {
			dfs(graph, visited, mp, x, component);
		}
	}
}

void findConnectedComponents(vector<vector<int>>& graph, map<int, vector<int>>& mp) {
	vector<bool> visited(graph.size(), false);
	int component = 1;
	for (int i = 0; i < graph.size(); ++i) {
		if (!visited[i]) {
			mp[component] = vector<int>();
			dfs(graph, visited, mp, i, component);
			component++;
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

	map<int, vector<int>> mp;
	findConnectedComponents(graph, mp);

	for (auto x : mp) {
		cout << "Component: " << x.first << endl; //koq komp e podred
		for (auto node : x.second) {
			cout << node << " "; //koi sa
		}

		cout << endl;
	}
	
}

/*
5 3
1 0
2 1
3 4
----
5 3
2 0
0 3
3 0
	*/