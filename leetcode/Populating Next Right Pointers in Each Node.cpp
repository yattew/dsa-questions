// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
class Solution {
public:
    void helper(Node* &root) {
    
    if(!root)
        return;
        
    if(root->left and root->right)
        root->left->next = root->right;
    
    if(root->right and root->next)
        root->right->next = root->next->left;
    
    helper( root->left );
    helper( root->right );
    
    }

    Node* connect(Node* root) {

        helper(root);
        return root;

    }
};