// https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/
class Solution {
public:
int minDeletions(string s)
{
    unordered_map<char, int> mp;
    for (auto x : s)
    {
        if (mp.find(x) == mp.end())
            mp[x] = 1;
        else
            mp[x] += 1;
    }
    multiset<int,greater<int>> st;
    for(auto x: mp)
        st.insert(x.second);
    int m = *st.begin();
    auto it = st.begin();
    it++;
    int ct = 0;
    for(; it!=st.end(); it++)
    {
        if(m <=0)
        {
            ct+=*it;
            m++;
        }
        else if(*it >= m)
            ct+=*it-m+1;  
        else
        {
            m = *it;
            m++;
        }
        m--;
    }
    return ct;
}
};