class Solution {
public:
    int findPos(vector<int>& arr, int start, int end, int element) {
        for(int i = start; i <= end; i++) {
            if(arr[i] == element)   return i;
        }
        return -1;
    }

    TreeNode *solve(vector<int>& pre, vector<int>& in, int start, int end, int &i, int n) {
        if(start > end || i >= n)   return NULL;
        int element = pre[i++];
        TreeNode *root = new TreeNode(element);
        int pos = findPos(in, start, end, element);
        root->left = solve(pre, in, start, pos-1, i, n);
        root->right = solve(pre, in, pos+1, end, i, n);
        return root;
    }

    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n = pre.size();
        int ind = 0;
        TreeNode *ans = solve(pre, in, 0, n-1, ind, n);
        return ans;
    }
};
