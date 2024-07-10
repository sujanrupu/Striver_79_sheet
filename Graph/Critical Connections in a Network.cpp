class Solution {
public:
    int timer = 1;

    void dfs(int node, int parent, vector<vector<int>>& bridges, int tin[] , int low[], vector<int>& vis, vector<int>adj[]) {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        for(auto it : adj[node]) {
            if(it == parent)    continue;
            if(vis[it] == 0) {
                dfs(it, node, bridges, tin, low, vis, adj);
                low[node] = min(low[it], low[node]);
                if(low[it] > low[node]) 
                    bridges.push_back({it, node});
            }
            else
                low[node] = min(low[it], low[node]);
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        for(auto it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n, 0);
        int tin[n], low[n];
        vector<vector<int>>bridges;
        dfs(0, -1, bridges, tin, low, vis, adj);
        return bridges;
    }
};
