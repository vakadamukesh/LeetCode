class Solution {
public:
int solve(vector<int>&nums,int x)
{
    int count=0,ans=0,j=0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]%2)
        count++;
        while(count>x)
        {
            if(nums[j]%2)
            count--;
            j++;
        }
        ans+=(i-j+1);
    }
    return ans;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};