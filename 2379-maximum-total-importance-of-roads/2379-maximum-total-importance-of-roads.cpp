class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {

        vector<int>a(n,0);
        for(int i=0;i<roads.size();i++)
        {
            a[roads[i][0]]++;
            a[roads[i][1]]++;
        }
        sort(a.begin(),a.end());
        long long  ans=0;
        long long val=1;
        for(int i=0;i<n;i++)
        {
            ans+=(val*a[i]);
            val++;
        }
        return ans;
    }
};