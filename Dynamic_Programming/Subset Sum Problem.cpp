class Solution{   
public:

    bool solve(vector<int> arr, int sum, int n, vector <vector <int> >& dp){
        if(sum<0) return false;
        if(sum==0) return true;
        if(n==0) return false;
        
        if(dp[n-1][sum]!=-1)  return dp[n-1][sum];
        
        int include = solve(arr,sum-arr[n-1],n-1, dp);
        int exclude = solve(arr,sum,n-1, dp);
        dp[n-1][sum] = (include || exclude);
        return dp[n-1][sum];
    }
    
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector <vector <int> > dp(n, vector <int> (sum+1, -1));
        return solve(arr,sum,n, dp);
    }
};
