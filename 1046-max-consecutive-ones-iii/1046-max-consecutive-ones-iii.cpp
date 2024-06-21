class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0;
        int res=0;
        unordered_map<int,int>mp;
        while(j<nums.size())
        {
            mp[nums[j]]++;
            while((mp[0])>k)
            {
                mp[nums[i]]--;
                i++;
            }
            res=max(res,j-i+1);
            j++;
        }
        return res;
    }
};