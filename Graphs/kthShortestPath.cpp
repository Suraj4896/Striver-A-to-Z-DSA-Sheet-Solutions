#include<bits/stdc++.h> // For std::sort

using namespace std;

// Graph is represented as an adjacency list of pairs (neighbor, weight)
vector<vector<pair<int, int>>> adj;
vector<pair<int, vector<int>>> allPaths; // To store all valid paths with their weights
vector<bool> visited;

void dfs(int u, int dest, vector<int> &path, int weight)
{
  visited[u] = true; // Mark the current node as visited
  path.push_back(u); // Add current node to the path

  // If the destination is reached, store the current path and its weight
  if (u == dest)
  {
    allPaths.push_back({weight, path});
  }
  else
  {
    // Explore all neighbors of the current node
    for (auto &neighbor : adj[u])
    {
      int v = neighbor.first;  // Neighbor node
      int w = neighbor.second; // Edge weight
      if (!visited[v])
      {
        dfs(v, dest, path, weight + w); // Recursively visit the neighbor
      }
    }
  }

  // Backtrack
  path.pop_back();
  visited[u] = false;
}

int main()
{
  int n, m; // Number of nodes and edges
  int k = 3;
  cout << "Enter the number of nodes and edges: ";
  cin >> n >> m;

  // Resize adjacency list and visited array to accommodate 1-based indexing
  adj.resize(n + 1);            // Resize the adjacency list for n nodes (1-based indexing)
  visited.resize(n + 1, false); // Resize the visited array for n nodes

  cout << "Enter the edges (u v weight):\n";
  for (int i = 0; i < m; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w}); // Edge u -> v with weight w
    adj[v].push_back({u, w}); // Since the graph is undirected, also add v -> u
  }

  int src, dest;
  cout << "Enter source and destination nodes: ";
  cin >> src >> dest;

  vector<int> path;
  dfs(src, dest, path, 0); // Start DFS from source with initial weight 0

  // Sort the paths by their total weight
  sort(allPaths.begin(), allPaths.end());

  // Output all the paths from src to dest, sorted by weight
  cout << "All Paths from node " << src << " to node " << dest << " sorted by weight:\n";
  for (const auto &p : allPaths)
  {
    cout << "Path with total weight " << p.first << ": ";
    for (int node : p.second)
    {
      cout << node << " -> ";
    }
    cout << endl;
  }

  cout << endl
       << "The " << k << " th shortest path is : " << endl;
  for (auto it : allPaths[k - 1].second)
  {
    cout << it << " -> ";
  }

  return 0;
}