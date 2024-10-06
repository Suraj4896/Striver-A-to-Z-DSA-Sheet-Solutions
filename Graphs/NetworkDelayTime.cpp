#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int m = times.size();
        vector<pair<int,int>> adj[n+1];
        for(auto it : times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> shortTime(n+1, 1e9);
        shortTime[k] = 0;
        pq.push({0, k});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int time = it.first;
            int node = it.second;
            for(auto nbr : adj[node]){
                int adjNode = nbr.first;
                int tm = nbr.second;
                if(time + tm < shortTime[adjNode]){
                    shortTime[adjNode] = time + tm;
                    pq.push({time + tm, adjNode});
                }
            }
        }
        int maxTime = 0;
        for(int i=1; i<=n; i++){
            if(shortTime[i] == 1e9) return -1;
            maxTime = max(maxTime, shortTime[i]);
        }
        
        return maxTime;
    }
};