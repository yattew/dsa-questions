// https://takeuforward.org/data-structure/minimum-insertions-to-make-string-palindrome-dp-29/

#include <bits/stdc++.h>
using namespace std;

int solve(string s)
{
    size_t size = s.size();
    vector<vector<int>> dp(size, vector<int>(size, 0));
    for (int i = 1; i < size; i++)
    {
        int l = 0;
        int r = l + i;
        while (r < size)
        {
            int m = s[l] == s[r]
                        ? dp[l + 1][r - 1]
                        : INT_MAX;
            m = min(dp[l + 1][r] + 1, m);
            m = min(dp[l][r - 1] + 1, m);
            dp[l][r] = m;
            l++;
            r++;
        }
    }
    // for (auto x : dp)
    // {
    //     for (auto y : x)
    //         cout << y << " ";
    //     cout << endl;
    // }
    return dp[0].back();
}

int main()
{
    string s = "abcaa";
    cout << solve(s);
}