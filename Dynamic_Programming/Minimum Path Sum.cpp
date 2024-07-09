class Solution {
public:
    int solve(vector<vector<int>>& grid, int m, int n, int i, int j, vector<vector<int>>& dp) {
        if(i<0 || j<0)  return 1e9;
        if(i == 0 && j == 0)    return grid[i][j];
        if(dp[i][j]!=-1)    return dp[i][j];
        int right = grid[i][j] + solve(grid, m, n, i-1, j, dp);
        int bottom = grid[i][j] + solve(grid, m, n, i, j-1, dp);
        return dp[i][j] = min(right, bottom);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return solve(grid, m, n, n-1, m-1, dp);
    }
};
