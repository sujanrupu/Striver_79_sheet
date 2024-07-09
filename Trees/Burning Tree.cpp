class Solution {
  public:
    Node *findTarget(Node *root, unordered_map<Node*, Node*>& parent, int target) {
        if(!root)   return NULL;
        queue<Node*>q;
        q.push(root);
        Node *targetNode = NULL;
        while(!q.empty()) {
            Node *front = q.front(); q.pop();
            if(front->data == target)    targetNode = front;
            if(front->left) {
                parent[front->left] = front;
                q.push(front->left);
            }
            if(front->right) {
                parent[front->right] = front;
                q.push(front->right);
            }
        }
        return targetNode;
    }
    
    int solve(Node *root, unordered_map<Node*, Node*>& parent, Node *targetNode) {
        if(!root)   return 0;
        unordered_map<Node*, bool>isBurnt;
        queue<Node*>q;
        q.push(targetNode);
        isBurnt[targetNode] = 1;
        int T = 0;
        while(!q.empty()) {
            int size = q.size();
            bool isFireSpread = 0;
            for(int i = 0; i < size; i++) {
                Node *front = q.front();    q.pop();
                if(front->left && !isBurnt[front->left]) {
                    q.push(front->left);
                    isBurnt[front->left] = 1;
                    isFireSpread = 1;
                }
                if(front->right && !isBurnt[front->right]) {
                    q.push(front->right);
                    isBurnt[front->right] = 1;
                    isFireSpread = 1;
                }
                if(parent[front] && !isBurnt[parent[front]]) {
                    q.push(parent[front]);
                    isBurnt[parent[front]] = 1;
                    isFireSpread = 1;
                }
            }
            if(isFireSpread)    ++T;
        }
        return T;
    }
  
    int minTime(Node* root, int target) 
    {
        if(!root)   return 0;
        unordered_map<Node*, Node*>parent;
        Node *targetNode = findTarget(root, parent, target);
        int ans = solve(root, parent, targetNode);
        return ans;
    }
};
