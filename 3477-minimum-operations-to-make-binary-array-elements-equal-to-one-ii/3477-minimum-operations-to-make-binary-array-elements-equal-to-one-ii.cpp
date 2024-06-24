class Solution {
public:
    int minOperations(vector<int>& nums) {
        int pre=0,ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==pre)
            {
                pre=1^pre;
                ans++;
            }
        }
        return ans;
    }
};