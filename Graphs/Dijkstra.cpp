#include <bits/stdc++.h> 
using namespace std;

//using Priority Queue
vector <int> dijkstraPriorityQueue(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dis(V, 1e9);
        dis[S] = 0;
        pq.push({0, S});
        while(!pq.empty()){
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            for(auto it : adj[node]){
                int edge = it[1];
                int adjNode = it[0];
                int distance = dist + edge;
                if(distance < dis[adjNode]){
                    dis[adjNode] = distance;
                    pq.push({distance, adjNode});
                }
            }
        }
        return dis;
    }

    //using Set
    vector <int> dijkstraSet(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int, int>> st;
        vector<int> dis(V, 1e9);
        dis[S] = 0;
        st.insert({0, S});
        while(!st.empty()){
            auto ele = *(st.begin());
            int node = ele.second;
            int dist = ele.first;
            st.erase(ele);
            for(auto it : adj[node]){
                int adjNode = it[0];
                int wt = it[1];
                int distance = dist + wt;
                int prev = dis[adjNode];
                if(distance < dis[adjNode]){
                    if(st.find({prev, adjNode}) != st.end()){
                        st.erase({prev, adjNode});
                    }
                    dis[adjNode] = distance;
                    st.insert({distance, adjNode});
                }
            }
        }
        return dis;
    }


    void printShortestPath(int V, const vector<int>& dist, int S) {
    cout << "Shortest paths from node " << S << ":\n";
    for (int i = 0; i < V; i++) {
        if (dist[i] == 1e9) {
            cout << S << " -> " << i << " : No path\n";
        } else {
            cout << S << " -> " << i << " : " << dist[i] << endl;
        }
    }
}

int main() {
    int V = 5; // Number of vertices
    int S = 0; // Source vertex

    // Adjacency list: adj[node] = {{adjNode, edgeWeight}, ...}
    vector<vector<int>> adj[V];
    
    // Graph edges: (source, destination, weight)
    adj[0].push_back({1, 4});
    adj[0].push_back({2, 4});
    adj[1].push_back({2, 2});
    adj[2].push_back({3, 3});
    adj[2].push_back({4, 1});
    adj[2].push_back({5, 6});
    adj[3].push_back({5, 2});
    adj[4].push_back({5, 3});
    
    // Running Dijkstra's algorithm
    vector<int> dist = dijkstraPriorityQueue(V, adj, S);
    
    // Printing shortest path from source S to all other nodes
    printShortestPath(V, dist, S);
    
    return 0;
}