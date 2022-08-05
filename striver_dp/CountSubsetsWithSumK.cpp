// https://takeuforward.org/data-structure/count-subsets-with-sum-k-dp-17/
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> arr, int k)
{
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
    for(auto row:dp)
        ct+=row.back();
    return ct;
}
int main()
{
    vector<int> arr = {1,2,2,3};
    int k = 3;
    cout<<solve(arr,k);
}