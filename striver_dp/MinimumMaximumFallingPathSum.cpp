// https://takeuforward.org/data-structure/minimum-maximum-falling-path-sum-dp-12/

#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> grid)
{
    int r_lm = grid.size() - 1;
    int c_lm = grid[0].size() - 1;
    vector<vector<int>> dp(
        r_lm + 1,
        vector<int>(c_lm + 1, 0));
    int r_it = r_lm;
    int c_it = 0;
    for (auto x : grid[r_it])
        dp[r_it][c_it++] = x;
    r_it--;
    while (r_it >= 0)
    {
        c_it = 0;
        while (c_it <= c_lm)
        {
            int l = INT_MIN, d = INT_MIN, r = INT_MIN;
            if (c_it > 0)
                l = dp[r_it + 1][c_it - 1];
            d = dp[r_it + 1][c_it];
            if (c_it < c_lm)
                r = dp[r_it + 1][c_it + 1];
            dp[r_it][c_it] = grid[r_it][c_it] + max(max(l, d), r);
            c_it++;
        }
        r_it--;
    }
    int res = 0;
    for (auto el : dp[0])
        res = max(res, el);
    return res;
}

int main()
{
    vector<vector<int>> grid = {
        {1, 2, 10, 4},
        {100, 3, 2, 1},
        {1, 1, 20, 2},
        {1, 2, 2, 1}};
    
    cout << solve(grid);
}