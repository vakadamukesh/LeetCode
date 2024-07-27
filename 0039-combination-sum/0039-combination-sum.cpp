class Solution {
public:
    void util(int ind,int sum,int target,vector<int> candidates,vector<int> com,vector<vector<int>> & combinations)
    {
        if(sum>=target or ind>=candidates.size())
        {
            if(sum==target) combinations.push_back(com);
            return;
        }
            com.push_back(candidates[ind]);
            util(ind,sum+candidates[ind],target,candidates,com,combinations);
            com.pop_back();
            util(ind+1,sum,target,candidates,com,combinations);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> combinations;
        vector<int> com;
        util(0,0,target,candidates,com,combinations);
        return combinations;
    }
};