class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int ans = 0;
        for(int i=0; i<nums.size(); i++)
        {
            int val = nums[i];
            if(val == k)      ans++;
            for(int j=i+1; j<nums.size() && k%nums[j]==0; j++){
                val = lcm(nums[j], val);
                if(val>k)
                break;
                if(val == k)
                    ans++; 
            }
        }
        return ans;
    }
};