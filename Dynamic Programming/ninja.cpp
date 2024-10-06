#include <bits/stdc++.h> 
using namespace std;

//recursion
int solve(int day, int last, vector<vector<int>>& points){
    //base case
    if(day == 0){
        int maxi = 0;
        for(int task = 0; task < 3; task++){
            if(task != last) maxi = max(maxi, points[0][task]);
        }
        return maxi;
    }

    int maxi = 0;
    for(int task = 0; task < 3; task++){
        if(task != last){
            int point = points[day][task] + solve(day-1, task, points);
            maxi = max(maxi, point);
        }
    }
    return maxi;
}



int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> prev(4,0);

    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][1], max(points[0][2], points[0][1]));

    for(int day = 1; day<n; day++){
        vector<int>temp(4,0);
        for(int last = 0; last<4; last++){
            temp[last] = 0;

            for(int task=0; task<3; task++){
                if(task != last){
                    int activity = points[day][task] + prev[task];
                    temp[last] = max(temp[last], activity);
                }
            }
        }
        prev = temp;
    }
    return prev[3];
}