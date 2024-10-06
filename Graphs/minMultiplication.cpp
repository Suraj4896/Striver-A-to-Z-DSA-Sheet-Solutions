#include <bits/stdc++.h> 
using namespace std;


    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<pair<int, int>> q;
        vector<int> steps(100000, 1e9);
        q.push({0, start});
        steps[start] = 0;
        while(!q.empty()){
            auto ele = q.front();
            int step = ele.first;
            int node = ele.second;
            q.pop();
            if(node == end) return step;
            for(auto it : arr){
                int val = (node * it) % 100000;
                if(step+1 < steps[val]){
                    steps[val] = step+1;
                    q.push({step+1, val});
                }
            }
        }
        return -1;
    }