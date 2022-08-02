// https://takeuforward.org/data-structure/3-d-dp-ninja-and-his-friends-dp-13/
#include <bits/stdc++.h>
using namespace std;
int solve(int i,
          int j1,
          int j2,
          int n,
          int m,
          vector<vector<int>> grid,
          vector<vector<vector<int>>> &dp)
{
    if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
        return -1e9;

    if (i == n - 1)
    {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }

    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];

    int maxi = INT_MIN;
    for (int di = -1; di <= 1; di++)
    {
        for (int dj = -1; dj <= 1; dj++)
        {
            int ans;
            if (j1 == j2)
                ans = grid[i][j1] + solve(i + 1, j1 + di, j2 + dj, n, m, grid, dp);
            else
                ans = grid[i][j1] + grid[i][j2] + solve(i + 1, j1 + di, j2 + dj, n, m, grid, dp);
            maxi = max(maxi, ans);
        }
    }
    return dp[i][j1][j2] = maxi;
}
int main()
{
    vector<vector<int>> grid = {
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5},
    };
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<vector<int>>> dp(
        grid.size(),
        vector<vector<int>>(
            grid[0].size(),
            vector<int>(
                grid[0].size(),
                -1)));
    cout << solve(0, 0, m - 1, n, m, grid, dp);
}