class Solution {
public:
int solve(vector<vector<int>>&dp,int m,int n)
{
    if(dp[m][n]!=-1)
    return dp[m][n];
    if(m==1)
    return 1;
    if(n==1)
    return 1;
    return dp[m][n]=solve(dp,m-1,n)+solve(dp,m,n-1);
}
    int uniquePaths(int m, int n) {
       vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
       return solve(dp,m,n);
    }
};