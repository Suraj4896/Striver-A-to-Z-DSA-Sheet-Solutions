#include <bits/stdc++.h> 
using namespace std;

vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int,int>> adj[n+1];
        for(auto it : edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dis(n+1, 1e9);
        vector<int> parent(n+1);
        for(int i=1; i<=n; i++) parent[i] = i;
        pq.push({0,1});
        dis[1] = 0;
        while(!pq.empty()){
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            for(auto it : adj[node]){
                int edge = it.second;
                int adjNode = it.first;
                int distance = dist + edge;
                if(distance < dis[adjNode]){
                    dis[adjNode] = distance;
                    pq.push({distance, adjNode});
                    parent[adjNode] = node;
                }
            }
        }
        if (dis[n] == 1e9) return {-1};
        vector<int> ans;
        int node = n;
        while(node != 1){
            ans.push_back(node);
            node = parent[node];
        }
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        return ans;
    }


    int main()
{
    // Driver Code

    int V = 5, E = 6;
    vector<vector<int>> edges = {{1, 2, 2}, {2, 5, 5}, {2, 3, 4}, {1, 4, 1}, {4, 3, 3}, 
    {3, 5, 1}};
    vector<int> path = shortestPath(V, E, edges);

    for (int i = 0; i < path.size(); i++)
    {

        cout << path[i] << " -> ";
    }
    cout << endl;
    return 0;
}