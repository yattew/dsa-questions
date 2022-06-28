// https://leetcode.com/problems/minimum-depth-of-binary-tree/
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
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        else if(root->left==NULL && root->right==NULL)
            return 1;
        else{
            int l = minDepth(root->left);
            int r = minDepth(root->right);
            if(l == 0)
                return r+1;
            else if(r == 0)
                return l+1;
            else
                return min(l,r)+1;
        }
    }
};