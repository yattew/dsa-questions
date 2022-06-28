// https://leetcode.com/problems/sort-colors/
class Solution {
public:
    void sortColors(vector<int> &nums)
    {
        int it = 0;
        int buckets[3] = {0,0,0};
        for(auto x: nums)
            buckets[x]++;
        for(int x = 0; x<3; x++)
            for(int i = 0; i<buckets[x]; i++)
                nums[it++] = x;
    }
};