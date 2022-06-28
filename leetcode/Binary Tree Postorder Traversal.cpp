// https://leetcode.com/problems/binary-tree-postorder-traversal/
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        vector<int> temp;
        if(!root){
            return res;
        }
        if(root->left){
            temp = postorderTraversal(root->left);
            append(res,temp);
        }
        if(root->right){
            temp = postorderTraversal(root->right);
            append(res,temp);
        }
        res.push_back(root->val);
        
        
        return res;
    }
    void append(vector<int>& a, vector<int>& b){
       for(auto x: b){
           a.push_back(x);
       } 
    }
};