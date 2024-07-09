class Solution {
public:
    int ans = INT_MIN;

    int findMax(TreeNode *root) {
        if(!root)   return 0;
        return root->val + max(0, max(findMax(root->left), findMax(root->right)));
    }

    void solve(TreeNode *root) {
        if(!root)   return ;
        int left = findMax(root->left);
        int right = findMax(root->right);
        if(left < 0)    left = 0;
        if(right < 0)   right = 0;
        solve(root->left);
        solve(root->right);
        ans = max(ans, root->val + left + right);
    }

    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};
