class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>arr;
        for(int i = 0; i < nums1.size(); i++)   arr.push_back(nums1[i]);
        for(int i = 0; i < nums2.size(); i++)   arr.push_back(nums2[i]);
        sort(arr.begin(), arr.end());
        if(arr.size()%2 == 1)   return arr[arr.size()/2];
        double a = arr[arr.size()/2 - 1], b = arr[arr.size()/2];
        double avg = (a + b)/2;
        return avg;
    }
};
