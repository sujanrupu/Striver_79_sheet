class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0;
        for(int i = 0; i < g.size(); i++) {
            int j = 0, count = 0;
            while(j < s.size() && count == 0) {
                if(s[j] >= g[i]) {
                    ans++;
                    count++;
                    s[j] = 0;
                }
                j++;
            }
        }
        return ans;
    }
};
