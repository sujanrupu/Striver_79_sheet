class Solution{
  public:
    int solve(int price[], int n, vector<int>& dp) {
        if(n < 0)   return -1e9;
        if(n == 0)  return 0;
        if(dp[n]!=-1)   return dp[n];
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++) {
            int ans = price[i] + solve(price, n - (i+1), dp);
            maxi = max(maxi, ans);
        }
        return dp[n] = maxi;
    }
  
    int cutRod(int price[], int n) {
        vector<int>dp(n+1, -1);
        return solve(price, n, dp);
    }
};
