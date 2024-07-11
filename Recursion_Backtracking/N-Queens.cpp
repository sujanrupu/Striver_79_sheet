class Solution {
public:
    void addSolution(vector<vector<int>>& board, int n, vector<vector<string>>& ans) {
        vector<string>temp;
        for(int i = 0; i < n; i++) {
            string str = "";
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 1)    str.push_back('Q');
                else    str.push_back('.');
            }
            temp.push_back(str);
        }
        ans.push_back(temp);
    }

    bool isSafe(vector<vector<int>>& board, int row, int col) {
        int n = board.size();
        int x = row, y = col;
        while(y >= 0) {
            if(board[x][y--] == 1)  return false;
        }
        y  =col;
        while(x < n && y >= 0) {
            if(board[x++][y--] == 1)    return false;
        }
        x = row, y = col;
        while(x >= 0 && y >= 0) {
            if(board[x--][y--] == 1)    return false;
        }
        return true;
    }

    void solve(int n, int col, vector<vector<int>>& board, vector<vector<string>>& ans) {
        if(col == n) {
            addSolution(board, n, ans);
            return ;
        }
        for(int row = 0; row < n; row++) {
            if(isSafe(board, row, col)) {
                board[row][col] = 1;
                solve(n, col+1, board, ans);
                board[row][col] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>>board(n, vector<int>(n, 0));
        vector<vector<string>>ans;
        solve(n, 0, board, ans);
        return ans;
    }
};
