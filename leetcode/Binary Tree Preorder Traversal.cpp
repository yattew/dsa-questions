// https://leetcode.com/problems/binary-tree-preorder-traversal/
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        vector<int> temp;
        if(!root){
            return res;
        }
        res.push_back(root->val);
        if(root->left){
            temp = preorderTraversal(root->left);
            append(res,temp);
        }
        if(root->right){
            temp = preorderTraversal(root->right);
            append(res,temp);
        }
        return res;
    }
    void append(vector<int>& a, vector<int>& b){
       for(auto x: b){
           a.push_back(x);
       } 
    }
};