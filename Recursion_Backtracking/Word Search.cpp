class Solution {
public:
    pair<int, int>find(vector<vector<char>>arr, char ch) {
        for(int i = 0; i < arr.size(); i++) {
            for(int j = 0; j < arr[0].size(); j++) {
                if(arr[i][j] == ch)
                    return {i, j};
            }
        }
        return {-1, -1};
    }

    bool exist(vector<vector<char>>& board, string word) {
        vector<pair<int, int>>v;
        for(int i = 0; i < word.length(); i++) {
            pair<int, int>p = find(board, word[i]);
            if(p.first == -1 && p.second == -1) return false;
            v.push_back(p);
        }
        for(int i = 0; i < v.size()-1; i++) {
            if( (v[i].first == v[i+1].first && abs(v[i+1].second - v[i].second == 1)) ||
                (v[i].second == v[i+1].second && abs(v[i+1].first - v[i].first) == 1) )
                    return false;
        }
        return true;
    }
};
