class Solution {
public:
    int helper(int ind,int prev,int n,vector<int>& arr1,vector<int>& arr2,vector<unordered_map<int,int>>& dp){
        if(ind == n)
            return 0;
        if(dp[ind][prev])
            return dp[ind][prev];
        int ans = INT_MAX-1;
        if(arr1[ind] > prev)
            ans = min(ans,helper(ind+1,arr1[ind],n,arr1,arr2,dp));
        auto x = upper_bound(arr2.begin(),arr2.end(),prev);
        if(x != arr2.end())
            ans = min(ans,1 + helper(ind+1,*x,n,arr1,arr2,dp));
        return dp[ind][prev] = ans;
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        vector<unordered_map<int,int>> dp(2001);
        int ans = helper(0,-1,arr1.size(),arr1,arr2,dp);
        return (ans >= INT_MAX-1) ? -1 : ans;
    }
};