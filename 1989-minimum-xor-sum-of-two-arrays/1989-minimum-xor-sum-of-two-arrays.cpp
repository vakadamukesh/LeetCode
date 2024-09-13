class Solution {
public:
    int dp[15][35000];
    int recurse(int curr, int mask, vector<int>& nums1, vector<int>& nums2){
        if(curr>=nums1.size()){
            cout<<mask<<endl;
            return 0;
        }

        if(dp[curr][mask]!=-1){
            return dp[curr][mask];
        }

        int ans = 1e9;

        for(int i=0;i<nums2.size();i++){
            if((mask&(1<<i))==0){
                ans = min(ans, (nums1[curr]^nums2[i]) + recurse(curr+1, mask^(1<<i), nums1, nums2));
            }
        }

        return dp[curr][mask] = ans;
    }
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int mask = 0;

        memset(dp, -1, sizeof(dp));

        int ans = recurse(0, mask, nums1, nums2);

        return ans;
    }
};