class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        for(int i = 0; i < heights.size(); i++) {
            int j = i;
            int left = 0, right = 0;
            while(j >= 0 && heights[j] >= heights[i]) {
                left++; j--;
            }
            j = i;
            while(j < heights.size() && heights[j] >= heights[i]) {
                right++;    j++;
            }
            ans = max(ans, heights[i] * (right + left - 1));
        }
        return ans;
    }
};
