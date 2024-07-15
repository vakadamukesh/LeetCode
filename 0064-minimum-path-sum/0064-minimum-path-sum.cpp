class Solution {
public:
int solve(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp)
{
    if(dp[i][j]!=-1)
    return dp[i][j];
    if(i==0)
    {
        int a=0;
        for(int k=0;k<=j;k++)
        {
            a+=grid[i][k];;
        }
        return a;
    }
    if(j==0)
    {
        int a=0;
        for(int k=0;k<=i;k++)
        {
            a+=grid[k][j];
        }
        return a;
    }
    return dp[i][j]=grid[i][j]+min(solve(i-1,j,grid,dp),solve(i,j-1,grid,dp));
}
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,grid,dp);
    }
};