class Solution {
public:
int dp[1005][2][105];
int f(int i,int canbuy,vector<int>&v,int trans,int k)
{
    int n=v.size();
    if(i==n||trans>=k)return 0;
    if(dp[i][canbuy][trans]!=-1)return dp[i][canbuy][trans];
    if(canbuy)
    {
        dp[i][canbuy][trans]=max(-v[i]+f(i+1,0,v,trans,k),f(i+1,1,v,trans,k));//if bought or skip for buying
    }
    else
    {
        dp[i][canbuy][trans]=max(v[i]+f(i+1,1,v,trans+1,k),f(i+1,0,v,trans,k));// if sold or skip for selling
    }
    return dp[i][canbuy][trans];
}
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof dp);
        return f(0,1,prices,0,k);
    }
};