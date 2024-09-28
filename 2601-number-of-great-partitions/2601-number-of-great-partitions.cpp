class Solution {
public:
    long mod = 1000000007;
    long dp[1001][1001];
    long recurse(int curr, int currSum, vector<int>& nums, int k){
        if(curr>=nums.size()){
            return 1;
        }

        if(dp[curr][currSum]!=-1){
            return dp[curr][currSum];
        }

        long ans = recurse(curr+1, currSum, nums, k)%mod;

        if(currSum + nums[curr] < k){
            ans = (ans%mod + recurse(curr+1, currSum + nums[curr], nums, k)%mod)%mod;
        }

        return dp[curr][currSum] = ans;
    }   
    int countPartitions(vector<int>& nums, int k) {

        long sum = accumulate(nums.begin(), nums.end(),1ll);
        if(sum < 2*k){
            return 0;
        }
        memset(dp,-1,sizeof(dp));
        long totalPartitions = 1;
        for(int i=1;i<=nums.size();i++){
            totalPartitions = (2%mod * totalPartitions%mod)%mod;
        }
        long falsegroups = (2%mod * recurse(0,0,nums,k)%mod)%mod;
        return (totalPartitions - falsegroups + mod)%mod;
    }
};

