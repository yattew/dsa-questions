// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
class Solution {
public:
    int binsearch_l(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        while (!(low > high))
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                if (mid > low && nums[mid - 1] == target)
                {
                    high = mid - 1;
                    continue;
                }
                return mid;
            }
            if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
    int binsearch_r(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        while (!(low > high))
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                if (mid < high && nums[mid + 1] == target)
                {
                    low = mid + 1;
                    continue;
                }
                return mid;
            }
            if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        int l = binsearch_l(nums,target);
        int r = binsearch_r(nums,target);
        vector<int> ret = {l,r};
        return ret;
    }
};