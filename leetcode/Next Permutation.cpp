// https://leetcode.com/problems/next-permutation/
class Solution {
public:
    void nextPermutation(vector<int> &perm)
    {
        auto it = rbegin(perm);
        while ((it + 1) != rend(perm) && *it <= *(it + 1))
        {
            it++;
        }
        it++;
        if (it == rend(perm))
        {
            reverse(perm.begin(), perm.end());
        }
        else
        {
            auto it_temp = it - 1;
            auto it_min_val = it - 1;
            while (true)
            {
                if (it_temp == rbegin(perm))
                {
                    if (*it_temp <= *it_min_val && *it_temp>*it)
                        it_min_val = it_temp;
                    it_temp--;
                    break;
                }
                if (*it_temp <= *it_min_val && *it_temp>*it)
                    it_min_val = it_temp;
                it_temp--;
            }
            swap(*it, *it_min_val);
            reverse(rbegin(perm), it);
        }
    }
};