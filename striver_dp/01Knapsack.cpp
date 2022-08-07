// https://takeuforward.org/data-structure/0-1-knapsack-dp-19/
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> wt, vector<int> val, int size)
{
    vector<vector<int>> dp(
        wt.size(),
        vector<int>(size, -1));
    for (int r = 0; r < wt.size(); r++)
    {
        for (int c = 0; c < size; c++)
        {
            if (wt[r] == c + 1)
            {
                dp[r][c] = val[r];
            }
            if (wt[r] < c + 1 && r > 0)
            {
                dp[r][c] = val[r] + dp[r - 1][c + 1 - wt[r]];
            }
            if (r > 0 && dp[r - 1][c] > dp[r][c])
            {
                dp[r][c] = dp[r - 1][c];
            }
            if (c > 0 && dp[r][c - 1] > dp[r][c])
            {
                dp[r][c] = dp[r][c - 1];
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
    vector<int> wt{1, 2, 4, 5};
    vector<int> val{5, 4, 8, 6};
    int size = 5;
    cout << solve(wt, val, size);
}