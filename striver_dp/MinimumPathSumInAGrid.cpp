// https://takeuforward.org/data-structure/minimum-path-sum-in-a-grid-dp-10/
#include <bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>> grid)
{
    int r_lim = grid.size() - 1;
    int c_lim = grid[0].size() - 1;
    vector<vector<int>> dp(
        r_lim + 1,
        vector<int>(c_lim + 1, -1));
    int r_it = r_lim;
    int c_it = c_lim;
    // dp[r_it][c_it] = grid[r_it][c_it];
    while (r_it >= 0)
    {
        c_it = c_lim;
        while (c_it >= 0)
        {
            int curr_sum = grid[r_it][c_it];
            int r_sum = INT_MAX;
            int d_sum = INT_MAX;
            if (c_it + 1 <= c_lim)
                r_sum = dp[r_it][c_it + 1];
            if (r_it + 1 <= r_lim)
                d_sum = dp[r_it + 1][c_it];
            dp[r_it][c_it] = curr_sum;
            if (r_sum != INT_MAX || d_sum != INT_MAX)
                dp[r_it][c_it] += min(r_sum, d_sum);
            c_it--;
        }
        r_it--;
    }
    return dp[0][0];
}
int main()
{
    vector<vector<int>> grid = {
        {5, 9, 6},
        {0, 5, 2},
    };
    cout << solve(grid);
}