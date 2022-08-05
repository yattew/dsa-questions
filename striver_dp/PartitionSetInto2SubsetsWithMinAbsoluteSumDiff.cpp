// https://takeuforward.org/data-structure/partition-set-into-2-subsets-with-min-absolute-sum-diff-dp-16/
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> arr)
{
    int k = 0;
    for (auto x : arr)
        k += x;
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
            if ((diff > 0 && dp[r - 1][diff - 1]) || arr[r] == c + 1)
                dp[r][c] = true;
            else
                dp[r][c] = dp[r - 1][c];
        }
    }
    vector<bool> last_row = dp[dp.size() - 1];
    // for (auto x : last_row)
    //     cout << x << " ";
    // cout << endl;
    int min_diff = INT_MAX;
    for (int i = 1; i <= last_row.size(); i++)
    {

        int diff = INT_MAX;
        if (last_row[i-1])
            diff = abs((k - i) - i);
        // cout<<k<<" "<<i<<" "<<" "<<diff<<endl;
        min_diff = min(min_diff, diff);
    }
    return min_diff;
}
int main()
{
    vector<int> arr = {8,6,5};
    cout << solve(arr);
}