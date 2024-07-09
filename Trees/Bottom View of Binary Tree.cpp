class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int>ans;
        if(!root)   return ans;
        map<int, int>mp;
        queue<pair<Node*, int>>q;
        q.push({root, 0});
        while(!q.empty()) {
            Node *front = q.front().first;
            int data = q.front().second;
            q.pop();
            mp[data] = front->data;
            if(front->left)     q.push({front->left, data-1});
            if(front->right)    q.push({front->right, data+1});
        }
        for(auto it : mp)   ans.push_back(it.second);
        return ans;
    }
};
