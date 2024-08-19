class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> duplicates;
        for(auto currNum : nums){
            int eleIndx = abs(currNum) - 1;
            if(nums[eleIndx] < 0){
                duplicates.push_back(abs(currNum));
            }else
                nums[eleIndx] *= -1;
        }
        return duplicates;
    }
};