class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>>q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    vis[i][j] = 1;
                    q.push({{i, j}, 0});
                }
                else    vis[i][j] = 0;
            }
        }
        int time = 0;
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int T = q.front().second;
            q.pop();
            time = max(time, T);
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};
            for(int i = 0; i < 4; i++) {
                int nrow = row + dx[i];
                int ncol = col + dy[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && !vis[nrow][ncol]) {
                    q.push({{nrow, ncol}, time+1});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && !vis[i][j])   return -1;
            }
        }
        return time;
    }
};
