class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        ans.push_back({intervals[0][0],intervals[0][1]});
        for(int i=0;i<intervals.size();i++)
        {
            int n=ans.size();
             if(intervals[i][0]<=ans[n-1][1])
            {
                ans[n-1][1]=max(intervals[i][1],ans[n-1][1]);
            }
            else
            {
                ans.push_back({intervals[i][0],intervals[i][1]});
            }
        }
        return ans;
    }
};