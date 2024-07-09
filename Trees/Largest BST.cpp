class Solution{
    public:
    void inorder(Node *root, vector<int>& arr) {
        if(!root)   return ;
        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }
    
    bool isBST(Node* root) {
        if(!root)   return false;
        vector<int>arr;
        inorder(root, arr);
        for(int i = 0; i < arr.size()-1; i++) {
            if(arr[i] >= arr[i+1])  return false;
        }
        return true;
    }
    
    int height(Node *root) {
        if(!root)   return 0;
        return 1+height(root->left)+height(root->right);
    }
    
    int helper(Node *root) {
        if(!root)   return 0;
        if(isBST(root)) return height(root);
        int left = helper(root->left);
        int right = helper(root->right);
        int ans = max(left, right);
        return ans;
    }
    
    int largestBst(Node *root)
    {
    	if(!root)   return 0;
    	return helper(root);
    }
};
