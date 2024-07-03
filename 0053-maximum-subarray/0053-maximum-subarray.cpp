class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int cs=nums[0];
       int ma=cs;
       for(int i=1;i<nums.size();i++)
       {
         if(cs<0)
        cs=0;
        cs+=nums[i];
       
        ma=max(ma,cs);
       } 
       return ma;
    }
};