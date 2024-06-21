class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int c=0,j=0,ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                c++;
            }
            if(c>=2)
            {
                while(c>=2)
                {
                    if(nums[j]==0)
                    {
                        c--;
                    }
                    j++;
                }
            }
            ans=max(ans,i-j);
        
        }
        return ans;
    }
};