class Solution{
    public:
    vector<int>topo(int n, vector<int>adj[]) {
        int indegree[n] = {0};
        for(int i = 0; i < n; i++) {
            for(auto it : adj[i])
                indegree[it]++;
        }
        queue<int>q;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0)    q.push(i);
        }
        vector<int>ans;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0)   q.push(it);
            }
        }
        return ans;
    }
    
    string findOrder(string dict[], int N, int K) {
        vector<int>adj[K];
        for(int i = 0; i < N-1; i++) {
            string a = dict[i], b = dict[i+1];
            for(int j = 0; j < min(a.length(), b.length()); j++) {
                if(a[j]!=b[j]) {
                    adj[a[j] - 'a'].push_back(b[j] - 'a');
                    break;
                }
            }
        }
        vector<int>arr = topo(K, adj);
        string ans = "";
        for(auto it : arr)
            ans.push_back((char)(it + 'a'));
        return ans;
    }
};
