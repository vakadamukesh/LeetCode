class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
    vector<vector<pair<int,int>>> matrix(grid.size(),vector<pair<int,int>> (grid[0].size(),make_pair(0,0)));
    for(int j=0;j<grid.size();j++)
    {    
        int cntx=0;
        int cnty=0;
        for(int i=0;i<grid[0].size();i++)
        {
            if(grid[j][i]=='X')
            cntx++;
            if(grid[j][i]=='Y')
            cnty++;
            if(j==0)
            {
                matrix[j][i].first=cntx;
                matrix[j][i].second=cnty;
            }
            else
            {
                matrix[j][i].first=cntx+matrix[j-1][i].first;
                matrix[j][i].second=cnty+matrix[j-1][i].second;
            }
        }
    }
    int ans=0;
    for(int i=0;i<grid.size();i++)
    {
        for(int j=0;j<grid[0].size();j++)
        {
            if((matrix[i][j].first>0)&&(matrix[i][j].first==matrix[i][j].second))
            ans++;
        }
    }
    
    return ans;
    }
};