class Solution {
public:
// int fib(int n,vector<int>&dp){
// if(n<=1){
//             return 1;
//         }
//         if(dp[n]!=-1){
//             return dp[n];
//         }
//         return dp[n]=fib(n-1,dp)+fib(n-2,dp);
// }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<n+1;i++)
        dp[i]=dp[i-1]+dp[i-2];
        return dp[n];
    }
};