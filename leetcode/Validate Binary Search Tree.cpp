// https://leetcode.com/problems/validate-binary-search-tree/
class Solution
{
public:
    TreeNode *temp = NULL;
    bool isValidBST(TreeNode *root)
    {
        if (!root) return true;
        if (!isValidBST(root->left))
            return false;
        if (temp && temp->val >= root->val)
            return false;
        temp = root;
        if (!isValidBST(root->right))
            return false;
        return true;
    }
};