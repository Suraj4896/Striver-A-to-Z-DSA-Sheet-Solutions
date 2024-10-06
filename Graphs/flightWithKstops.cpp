#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int m = flights.size();
        vector<pair<int,int>> adj[n];
        for(auto it : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int, pair<int, int>>> q;
        vector<int> price(n, 1e9);
        price[src] = 0;
        q.push({0, {0, src}});
        while(!q.empty()){
            auto ele = q.front();
            int stops = ele.first;
            int prices = ele.second.first;
            int city = ele.second.second;
            q.pop();

            if(stops > k) continue;
            for(auto it : adj[city]){
                int adjCity = it.first;
                int prc = it.second;
                if(prices + prc < price[adjCity] && stops <= k){
                    price[adjCity] = prices + prc;
                    q.push({stops+1 ,{prices + prc, adjCity}});
                }
            }
        }
        return price[dst] == 1e9 ? -1 : price[dst];
    }
};