class Solution {
public:
void solve(vector<int>&nums,vector<int>&res,vector<vector<int>>&ans,int ind)
{
    if(ind>nums.size())
    return ;
    if(ind==nums.size())
    {
        ans.push_back(res);
        return ;
    }
        res.push_back(nums[ind]);
        solve(nums,res,ans,ind+1);
        res.pop_back();
        solve(nums,res,ans,ind+1);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>res;
        solve(nums,res,ans,0);
        return ans;
    }
};