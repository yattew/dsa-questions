// https://takeuforward.org/data-structure/target-sum-dp-21/
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> arr, int target)
{
    int sm = 0;
    for (auto x : arr)
        sm += x;
    vector<vector<int>> dp(
        arr.size(),
        vector<int>(
            sm + 1,
            0));
    for (int it = 0; it < arr.size(); it++)
    {
        for (int c = 0; c < sm + 1; c++)
        {

            if (it > 0)
            {
                int diff = abs(c - arr[it]);
                int sum = c + arr[it];
                // cout << dp[it - 1][sum] << " " << sum << " ";
                // cout << endl;
                if (dp[it - 1][diff])
                {
                    dp[it][c] += dp[it - 1][diff];
                }
                if (sum < sm + 1 && dp[it - 1][sum])
                {
                    dp[it][c] += dp[it - 1][sum];
                }
            }
            else if (arr[it] == c)
            {
                dp[it][c]++;
            }
        }
        // for (auto x : dp)
        // {
        //     for (auto y : x)
        //         cout << y << " ";
        //     cout << endl;
        // }
        // cout << endl;
    }

    return dp[dp.size() - 1][target];
}
int main()
{
    vector<int> arr = {1, 2, 3, 1};
    int target = 3;
    cout << solve(arr, target);
}