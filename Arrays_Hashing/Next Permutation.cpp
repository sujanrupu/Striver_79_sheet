class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        string str = "";
        for(int i = 0; i < nums.size(); i++)    str.push_back((char)nums[i]);
        next_permutation(begin(str), end(str));
        for(int i = 0; i < str.length(); i++)   nums[i] = (int)str[i];
    }
};
