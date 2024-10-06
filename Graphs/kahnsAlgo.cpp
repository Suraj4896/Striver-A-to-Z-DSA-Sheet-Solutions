#include <bits/stdc++.h> 
using namespace std;

vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    queue<int> q;
	    vector<int> ans;
	    vector<int> indegree(V, 0);
	    for(int i=0; i<V; i++){
	        for(auto it : adj[i]){
	            indegree[it]++;
	        }
	    }
	    for(int i=0; i<V; i++){
	        if(indegree[i] == 0) q.push(i);
	    }
	    
	    while(!q.empty()){
	        int top = q.front();
	        q.pop();
	        ans.push_back(top);
	        for(auto it : adj[top]){
	            indegree[it]--;
	            if(indegree[it] == 0) q.push(it);
	        }
	    }
	    return ans;
	}