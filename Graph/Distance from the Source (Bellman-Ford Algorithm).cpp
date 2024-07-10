class Solution {
  public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int>dist(V, 1e8);
        dist[S] = 0;
        for(int i = 0; i < V-1; i++) {
            for(auto it : edges) {
                int src = it[0];
                int dst = it[1];
                int weight = it[2];
                if(dist[src] != 1e8 && dist[src] + weight < dist[dst]) 
                    dist[dst] = dist[src] + weight;
            }
        }
        for(auto it : edges) {
            int src = it[0];
            int dst = it[1];
            int weight = it[2];
            if(dist[src] != 1e8 && dist[src] + weight < dist[dst]) 
                return {-1};
        }
        return dist;
    }
};
