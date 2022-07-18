// https://takeuforward.org/data-structure/maximum-sum-of-non-adjacent-elements-dp-5/
#include <bits/stdc++.h>
using namespace std;
int max(vector<int> vec)
{
    int m = vec.front();
    for(auto x: vec)
        if(x>m)
            m = x;
    return m;
}
int main()
{
    vector<int> arr = {1, 2, 3, 1, 3, 5, 8, 1, 9};
    // arr = {2,1,4,9};
    vector<int> dp(arr.size(),-1);
    int it = 1;
    dp[0] = arr[0];
    while(it<arr.size())
    {
        int prev = 0;
        if(it-2>=0)
            prev = dp[it-2];
        dp[it] = max(dp[it-1],arr[it]+prev);
        it++;
    }
    // for(auto x: dp)
    //     cout<<x<<" ";
    cout<<max(dp);
}