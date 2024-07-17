class Solution {
public:
    int minInsertions(string s) {
        string mu=s;
        int m=s.length();
        reverse(mu.begin(),mu.end());
        vector<int>prev(m+1,0),curr(m+1,0);
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==mu[j-1])
                curr[j]=1+prev[j-1];
                else
                curr[j]=max(curr[j-1],prev[j]);
            }
            prev=curr;
        }
        return m-prev[m];
    }
};