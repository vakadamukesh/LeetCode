class Solution {
public:
    long long dp[100001][3];
    long long solve(int i, int flag, vector<int>& nums){
        if(i>=nums.size())return 0;
        if(dp[i][flag+1]!=-1)return dp[i][flag+1];
        
        long long op1 = flag*nums[i]+solve(i+1,-flag,nums);
        long long op2 = nums[i]+solve(i+1,-1,nums);
        
        return dp[i][flag+1] = max(op1,op2);
    }
    long long maximumTotalCost(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(0,1,nums);
    }
};