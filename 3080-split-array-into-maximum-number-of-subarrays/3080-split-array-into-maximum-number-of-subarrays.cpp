class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int n = nums.size();
        int score=0;
        int sum = nums[0];
        for(int i=0;i<n;i++){
            if(sum==0){
                sum=nums[i];
            }
            sum = sum & nums[i];
            if(sum==0){
                score++;
            }
        }
        if(score==0)
            score=1;
        return score;
    }
};