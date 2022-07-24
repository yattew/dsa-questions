// https://takeuforward.org/data-structure/grid-unique-paths-2-dp-9/
#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> grid)
{
    int rows = grid.size(), cols = grid[0].size();
    vector<vector<int>> dp(
        rows,
        vector<int>(cols, 0));
    int r_lim = grid.size() - 1;
    int c_lim = grid[0].size() - 1;
    int r_it = r_lim;
    int c_it = c_lim;
    dp[r_it][c_it] = 1;
    while(r_it>=0)
    {
        c_it = c_lim;
        while(c_it>=0)
        {
            if(c_it+1<=c_lim && grid[r_it][c_it+1]!=-1)
            {
                dp[r_it][c_it]+=dp[r_it][c_it+1];
            }
            if(r_it+1<=r_lim && grid[r_it+1][c_it]!=-1)
            {
                dp[r_it][c_it]+=dp[r_it+1][c_it];
            }
            c_it--;
        }
        r_it--;
    }
    return dp[0][0];
}

int main()
{
    vector<vector<int>> grid = {
        {0, -1, 0},
        {0, 0, -1},
        {0, 0, 0},
    };
    cout << solve(grid);
}