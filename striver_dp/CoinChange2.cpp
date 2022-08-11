// https://takeuforward.org/data-structure/coin-change-2-dp-22/
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> arr, int k)
{
    vector<vector<int>> dp(arr.size(), vector<int>(k + 1, 0));
    for (int r = 0; r < arr.size(); r++)
    {
        for (int c = 0; c <= k; c++)
        {
            if (arr[r] > c)
                if (c == 0)
                    dp[r][c] = 1;
                else if (r - 1 >= 0)
                    dp[r][c] = dp[r - 1][c];
                else
                    dp[r][c] = 0;
            else
            {
                if (r - 1 >= 0)
                {
                    dp[r][c] = dp[r][c - arr[r]] + dp[r - 1][c];
                }
                else if (c % arr[r] == 0)
                {
                    dp[r][c] = 1;
                }
            }
        }
    }
    // for (auto x : dp)
    // {
    //     for (auto y : x)
    //         cout << y << " ";
    //     cout << endl;
    // }
    return dp[dp.size() - 1][dp[0].size() - 1];
}
int main()
{
    vector<int> arr{1, 2, 3};
    int k = 4;
    cout << solve(arr, k);
}