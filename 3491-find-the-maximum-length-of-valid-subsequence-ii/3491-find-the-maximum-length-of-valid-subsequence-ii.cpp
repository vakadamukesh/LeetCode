class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int ans=2;
        for(int mod=0;mod<k;mod++)
        {
            vector<int>dp(k,0);
            for(int i=0;i<nums.size();i++)
            {
                int cr=nums[i]%k;
                int pr=(mod-cr+k)%k;
                dp[cr]=max(dp[cr],1+dp[pr]);
                ans=max(ans,dp[cr]);
            }
        }
        return ans;
    }
};