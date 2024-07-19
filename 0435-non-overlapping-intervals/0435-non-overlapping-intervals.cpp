class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& v) {
        int c=0;
        sort(v.begin(),v.end());
        for(int i=0;i<v.size()-1;i++)
        {
            if(v[i][1]>v[i+1][0])
            {
                if(v[i][1]>v[i+1][1])
                {
                    c++;
                }
                else
                {
                    c++;
                    v[i+1][1]=v[i][1];
                }
            }
        }
        return c;
    }
};