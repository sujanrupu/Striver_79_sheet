class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        sort(nums.begin(), nums.end());
        int count = 1, n = nums.size();
        for(int i = 0; i < n-1; i++) {
            if(nums[i] == nums[i+1])    count++;
            else {
                if(count > n/3) ans.push_back(nums[i]);
                count = 1;
            }
        }
        if(count > n/3) ans.push_back(nums[n-1]);
        return ans;
    }
};
