class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(),1);
        int ma=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    dp[i]=max(dp[i],1+dp[j]);
                    ma=max(ma,dp[i]);
                }
            }
        }
        return ma==INT_MIN?1:ma;
    }
};