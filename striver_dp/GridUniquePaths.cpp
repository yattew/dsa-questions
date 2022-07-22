// https://takeuforward.org/data-structure/grid-unique-paths-dp-on-grids-dp8/
#include <bits/stdc++.h>
using namespace std;

int helper(int r, int c, vector<vector<int>> &dp)
{
    int r_it = r - 1;
    int c_it = c - 1;
    int c_lim = c_it;
    int r_lim = r_it;
    dp[r_lim][c_lim] = 1;
    while (r_it >= 0)
    {
        c_it = c_lim;
        while (c_it >= 0)
        {
            if (c_it + 1 <= c_lim)
            {
                dp[r_it][c_it] += dp[r_it][c_it + 1];
            }
            if (r_it + 1 <= r_lim)
            {
                dp[r_it][c_it] += dp[r_it + 1][c_it];
            }
            c_it--;
        }
        r_it--;
    }
    return dp[0][0];
}

int solve(int r, int c)
{
    vector<vector<int>> dp(
        r,
        vector<int>(c, 0));
    return helper(r, c, dp);
}
int main()
{
    int r = 3, c = 3;
    cout << solve(r, c);
}