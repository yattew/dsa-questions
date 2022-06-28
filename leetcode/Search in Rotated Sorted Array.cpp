// https://leetcode.com/problems/search-in-rotated-sorted-array/
class Solution {
public:
int find_pivot(vector<int> &arr)
{
    int l = 0;
    int r = arr.size() - 1;
    int mid = -1;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        cout << mid << endl;
        if (
            mid > 0 &&
            mid < arr.size()-1&
            arr[mid] <= arr[mid - 1] &&
            arr[mid + 1] >= arr[mid])
            return mid;
        if (arr[mid] > arr[r])
            l = mid + 1;
        else
            r = mid - 1;
    }
    return mid;
}

int binary_search(vector<int> &nums, int target, int low, int high)
{
    while(low<=high)
    {
        int mid = low + (high - low)/2;
        if(nums[mid] == target)
            return mid;
        if(nums[mid] < target)
            low = mid+1;
        else
            high = mid-1;
    }
    return -1;
}

int search(vector<int> &nums, int target)
{
    int pivot = find_pivot(nums);
    int res = binary_search(nums, target, 0, pivot-1);
    return res == -1
        ? binary_search(nums,target,pivot,nums.size()-1)
        : res; 
    return -1;
}
};