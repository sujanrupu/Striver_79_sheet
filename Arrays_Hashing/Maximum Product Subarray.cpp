class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minProd = nums[0], maxProd = nums[0], ans = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            int temp = minProd;
            minProd = min({nums[i], minProd * nums[i], maxProd * nums[i]});
            maxProd = max({nums[i], temp * nums[i], maxProd * nums[i]});
            ans = max(ans, maxProd);
        }
        return ans;
    }
};
