// https://leetcode.com/problems/find-bottom-left-tree-value/description/
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
    pair<int,int> bottom_left;//pair<node,depth>
    int findBottomLeftValue(TreeNode* root) {
        do_dfs(root,1);
        return bottom_left.first;
    }
    void do_dfs(TreeNode*root, int depth){
        if(!root->right&&!root->left&&depth>=bottom_left.second){
            bottom_left.first = root->val;
            bottom_left.second = depth;
            return;
        }
        if(root->right){
            do_dfs(root->right,depth+1);
        }
        if(root->left){
            do_dfs(root->left, depth+1);
        }
        return;
    }
};