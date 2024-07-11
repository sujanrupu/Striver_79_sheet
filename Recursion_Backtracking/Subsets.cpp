class Solution {
public:
    void solve(vector<int>& nums, vector<int> output, vector<vector<int>>& ans, int i) {
        if(i >= nums.size()) {
            ans.push_back(output);
            return ;
        }
        solve(nums, output, ans, i+1);
        int element = nums[i];
        output.push_back(element);
        solve(nums, output, ans, i+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>output;
        solve(nums, output, ans, 0);
        return ans;
    }
};
