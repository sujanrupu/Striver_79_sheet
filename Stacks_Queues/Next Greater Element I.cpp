class Solution {
public:
    int findInd(vector<int>& arr, int element) {
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] == element)   return i;
        }
        return -1;
    }

    int findGreater(vector<int>& arr, int element) {
        int ind = findInd(arr, element);
        for(int i = ind+1; i < arr.size(); i++) {
            if(arr[i] > element)    return arr[i];
        }
        return -1;
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        for(int i = 0; i < nums1.size(); i++) {
            int element = findGreater(nums2, nums1[i]);
            ans.push_back(element);
        }
        return ans;
    }
};
