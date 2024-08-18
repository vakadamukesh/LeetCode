#define ll long long
class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) 
    { 
        int n=board.size();
        int m=board[0].size();
        vector<pair<int,int>>v[n];
        for(int i=0;i<n;i++)
        {   
            vector<pair<int,int>>columnSort;
            for(int j=0;j<m;j++)
            {
                columnSort.push_back({board[i][j],j});
            }
            sort(columnSort.begin(),columnSort.end());
            reverse(columnSort.begin(),columnSort.end());
            for(int j=0;j<3;j++)
            {
                v[i].push_back(columnSort[j]);
            }
        }
        ll ans=-1e18;
        for(int i=0;i<n;i++)
        {   
            int firstIndex=v[i][0].second;
            long long firstVal=v[i][0].first;
            
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {   
                     int ind=0;
                     while(v[j][ind].second==firstIndex)
                     {
                         ind++;
                     }
                    
                    int secondIndex=v[j][ind].second;
                    long long secondVal=v[j][ind].first;
                    
                    for(int k=0;k<n;k++)
                    {
                        if((i!=k) && (j!=k))
                        {
                             ind=0;
                             while(v[k][ind].second==firstIndex || v[k][ind].second==secondIndex)
                             {
                                 ind++;
                             }
                             int thirdIndex=v[j][ind].second;
                             long long thirdVal=v[k][ind].first;
                            long long total=firstVal+secondVal+thirdVal;
                            ans=max(ans,total);
                        }
                    }
                    
                }
                
            }
        }
        return ans;   
    }
};

