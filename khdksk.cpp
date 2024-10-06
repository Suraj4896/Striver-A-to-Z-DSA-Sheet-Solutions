#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(vector<int>& positions, vector<int>& healths, string directions){
        unordered_map<int,pair<int, char>> mp;
        stack<pair<int,pair<int, char>>> st;
        vector<int> ans;
        for(int i=0; i<positions.size(); i++){
            mp[positions[i]] = {healths[i], directions[i]};
        }
        sort(positions.begin(), positions.end());
        st.push({positions[0], mp[positions[0]]});
        for(int i=1; i<positions.size(); i++){
            if(!st.empty()){
                auto top = st.top();
                if(top.second.second == mp[positions[i]].second){
                    st.push({positions[i], mp[positions[i]]});
                }
                else if(top.second.second == 'R' && mp[positions[i]].second == 'L'){
                    if(top.second.first == mp[positions[i]].first){
                        st.pop();
                        mp.erase(top.first);
                        mp.erase(positions[i]);
                    }
                    else if(top.second.first > mp[positions[i]].first){
                        top.second.first--;
                        mp[top.first].first = top.second.first;
                        mp.erase(positions[i]);
                    }
                    else{
                        st.pop();
                        mp.erase(top.first);
                        mp[positions[i]].first--;
                        st.push({positions[i], mp[positions[i]]});
                    }
                }
                else{
                    st.push({positions[i], mp[positions[i]]});
                }
            }
        }
        for(auto i=mp.begin(); i!=mp.end(); i++){
            ans.push_back(i->second.first);
        }

        // reverse(ans.begin(), ans.end());

        return ans;
    }
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        if(directions.find_first_not_of(directions[0]) == string::npos){
            return healths;
        }
        else{
            return solve(positions, healths, directions);
        }
    }
};