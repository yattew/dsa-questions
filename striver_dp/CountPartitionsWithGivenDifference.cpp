// https://takeuforward.org/data-structure/count-partitions-with-given-difference-dp-18/
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> arr, int diff)
{
    int k = 0;
    for(auto x: arr)
        k+=x;
    vector<vector<bool>> dp(
        arr.size(),
        vector<bool>(k, false));
    int len = arr.size();
    for (int i = 0; i < k; i++)
        if (i + 1 == arr[0])
            dp[0][i] = true;
    for (int r = 1; r < len; r++)
    {
        for (int c = 0; c < k; c++)
        {
            int diff = c + 1 - arr[r];
            if ((diff > 0 && dp[r - 1][diff-1]) || arr[r] == c+1)
                dp[r][c] = true;
            else
                dp[r][c] = dp[r - 1][c];
        }
    }
    int ct = 0;
    for(int i = 0; i<dp[0].size(); i++)
    {
        int sm = i+1;
        int curr_diff = abs(dp[0].size() - sm);
        if(curr_diff == diff)
            ct++;
    }
    return ct;
}
int main()
{
    vector<int> arr = {5,2,6,4};
    int diff = 3;
    cout<< solve(arr,diff);
}