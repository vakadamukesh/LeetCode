class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int mi=INT_MAX,ma=INT_MAX;
        int mii=INT_MIN,maa=INT_MIN;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==1)
                {
                    mi=min(i,mi);
                    mii=max(i,mii);
                    ma=min(ma,j);
                    maa=max(maa,j);
                }
            }
        }
        return (maa-ma+1)*(mii-mi+1);
    }
};