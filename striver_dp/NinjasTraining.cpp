// https://takeuforward.org/data-structure/dynamic-programming-ninjas-training-dp-7/
#include<bits/stdc++.h>
using namespace std;

void print2D(vector<vector<int>> v)
{
    for(auto x: v)
    {
        for(auto y: x)
            cout<<y<<" ";
        cout<<endl;
    }
}

int vecMax(vector<int> v)
{
    int m = v.front();
    for(auto x: v)
        m = max(x,m);
    return m;
}


int solve(vector<vector<int>> points)
{
    vector<vector<int>> dp(points.size(), vector<int>{0,0,0});
    int it = points.size()-1;
    for(int i = 0; i<3; i++)
        dp[it][i] = points[it][i];
    it--;
    while(it>=0)
    { 
        for(int i = 0; i<3; i++)
        {
            int a = INT_MIN;
            int b = INT_MIN;
            if(i-1>0)
            {
                a = points[it][i]+dp[it+1][i-1];
            }
            if(i+1<3)
            {
                b = points[it][i]+dp[it+1][i+1];
            }
            dp[it][i] = max(a,b);
        }
        it--;
    }
    return vecMax(dp[0]);
}



int main()
{
    vector<vector<int>> points = {
        {10,40,70},
        {20,50,80},
        {30,60,90},
    };
    cout<<solve(points);
}