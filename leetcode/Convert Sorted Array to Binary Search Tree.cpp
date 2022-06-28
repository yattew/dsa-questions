// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if(nums.size()==0){
            return NULL;
        }
        if(nums.size()==1){
            return new TreeNode(nums[0]);
        }
        else{
            vector<int> l,r;
            TreeNode* l_tree,*r_tree,*curr_tree;
            int len = nums.size(),mid;
            for(int i = 0; i<len/2; i++){
                r.push_back(nums.back());
                nums.pop_back();
            }
            reverse(r.begin(),r.end());
            mid = nums.back();
            nums.pop_back();
            for(int i = 0; i<nums.size(); i++){
                l.push_back(nums[i]);
            }
            l_tree = sortedArrayToBST(l);
            r_tree = sortedArrayToBST(r);
            curr_tree = new TreeNode(mid,l_tree,r_tree);
            return curr_tree;
        }

    }
    
};