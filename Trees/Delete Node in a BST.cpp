class Solution {
public:
    TreeNode *findLast(TreeNode *root) {
        if(!root->right)   return root;
        return findLast(root->right);
    }

    TreeNode *helper(TreeNode *root) {
        if(!root->left)     return root->right;
        if(!root->right)    return root->left;
        TreeNode *rightChild = root->right;
        TreeNode *lastRight = findLast(root->left);
        lastRight->right = rightChild;
        return root->left;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)   return NULL;
        TreeNode *curr = root;
        if(root->val == key)    return helper(root);
        while(root) {
            if(root->val > key) {
                if(root->left && root->left->val == key) 
                    root->left = helper(root->left);
                else    root = root->left;
            }
            else if(root->val < key) {
                if(root->right && root->right->val == key)
                    root->right = helper(root->right);
                else    root = root->right;
            }
        }
        return curr;
    }
};
