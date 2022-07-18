// https://takeuforward.org/data-structure/dynamic-programming-frog-jump-with-k-distances-dp-4/
#include <bits/stdc++.h>
using namespace std;
int min(vector<int> vec)
{
    int m = vec.front();
    for(auto x: vec)
        if(x<m)
            m = x;
    return m;
}
int main()
{
    vector<int> height{30, 10, 60, 10, 60, 50};
    int k = 3;
    int idx = height.size() - 1;
    vector<int> dp(height.size(), -1);
    dp[idx] = 0;
    idx--;
    while (idx >= 0)
    {
        vector<int> jump_res(k,INT_MAX);
        for(int i = 1; i<=k; i++)
        {
            if(idx+i<=height.size()-1)
            {
                jump_res[i-1] = dp[idx+i] + abs(height[idx]-height[idx+i]);
            }
        }
        dp[idx] = min(jump_res);
        idx--;
    }
    cout<<dp[0];
}