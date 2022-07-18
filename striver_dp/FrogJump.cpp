#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> steps = {10,200,30,10};
    vector<int> dp(steps.size(),-1);
    int it = steps.size()-1;
    dp[it] = 0;
    it--;
    dp[it] = abs(steps[it] - steps[it+1]);
    it--;
    while(it>=0)
    {
        int a = abs(steps[it]-steps[it+1]) + dp[it+1];
        int b = abs(steps[it]-steps[it+2]) + dp[it+2];
        dp[it] = min(a,b);
        it--;
    }
    // for(auto x: dp)
    //     cout<<x<<" ";
    cout<<dp[0];

}