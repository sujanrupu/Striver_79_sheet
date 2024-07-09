class Solution {
public:
    void inorder(TreeNode *root, vector<int>& ans) {
        if(!root)   return ;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    bool findTarget(TreeNode* root, int k) {
        if(!root)   return false;
        vector<int>arr;
        inorder(root, arr);
        int start = 0, end = arr.size()-1;
        while(start < end) {
            int sum = arr[start] + arr[end];
            if(sum == k)  return true;
            else if(sum < k)    start++;
            else    end--;
        }
        return false;
    }
};
