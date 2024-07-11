class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        vector<int>ans;
        for(int i = 0; i < queries.size(); i++) {
            int res = -1;
            int j = 0;
            while(j < nums.size() && nums[j] <= queries[i][1]) {
                res = max(res, queries[i][0] ^ nums[j]);
                j++;
            }
            ans.push_back(res);
        }   
        return ans;
    }
};
