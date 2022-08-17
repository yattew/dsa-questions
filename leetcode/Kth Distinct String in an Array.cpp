// https://leetcode.com/problems/kth-distinct-string-in-an-array/
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,pair<int,int>> mp;
        int it = 0;
        for(auto str: arr)
        {
            if(mp.find(str)==mp.end())
                mp[str] = pair<int,int>(1,it);
            else
                mp[str] = pair<int,int>(mp[str].first+1,mp[str].second);
            it++;
        }
        vector<int> uncommon;
        for(auto x:mp)
            if(x.second.first==1)
                uncommon.push_back(x.second.second);
        sort(uncommon.begin(),uncommon.end());
        return uncommon.size()>=k?arr[uncommon[k-1]]:"";
    }
};