#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int m = prerequisites.size();
        vector<int> adj[numCourses];
        for(int i = 0; i < m; i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> indegree(numCourses, 0);
        for(int i = 0; i < numCourses; i++){
            for(auto it : adj[i]) indegree[it]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }
        vector<int> order;
        vector<int> empty;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            order.push_back(node);
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        return order.size() == numCourses ? order : empty;
    }
};