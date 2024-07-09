class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        sort(arr.begin(), arr.end());
        vector<int>ans(n, 0);
        if(arr[0] > 1)  ans[1] = 1;
        for(int i = 0; i < arr.size()-1; i++) {
            if(arr[i+1] - arr[i] > 1)   ans[1] = arr[i] + 1;
            if(arr[i] == arr[i+1])  ans[0] = arr[i];
        }
        if(ans[1] == 0) ans[1] = arr[arr.size() - 1] + 1;
        return ans;
    }
};
