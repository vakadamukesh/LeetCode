class Solution {
    private:
    void getCombinations(int i,int& n,int k,vector<vector<int>>& ans,vector<int>& temp){
        if(i>n){
            if(k==0){
              ans.push_back(temp);
            }
            return;
        }
        temp.push_back(i);
        getCombinations(i+1,n,k-1,ans,temp);
        temp.pop_back();
        getCombinations(i+1,n,k,ans,temp);
        
    }
public:
    vector<vector<int>> combine(int n, int k) {
       vector<vector<int>> ans;
       vector<int> temp;
       getCombinations(1,n,k,ans,temp);
       return ans;
    }
};