#include <bits/stdc++.h> 
using namespace std;

bool isCyclic(int V, vector<int> adj[]) {
        queue<int> q;
	    int cnt = 0;
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
	        cnt++;
	        for(auto it : adj[top]){
	            indegree[it]--;
	            if(indegree[it] == 0) q.push(it);
	        }
	    }
	    if(cnt == V) return false;
	    return true;
    }