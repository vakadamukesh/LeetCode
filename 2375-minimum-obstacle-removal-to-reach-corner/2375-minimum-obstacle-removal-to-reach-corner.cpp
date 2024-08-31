class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        priority_queue<pair<int,pair<int,int>>, 
                        vector<pair<int,pair<int,int>>>, 
                        greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});

        vector<vector<int>> vis(m,vector<int>(n,0));

        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,-1,0,1};
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            int obst = p.first;
            int r = p.second.first;
            int c = p.second.second;
            if(r==m-1 && c==n-1){
                return obst;
            }

            for(int i=0; i<4; i++){
                int nr = r+drow[i];
                int nc = c+dcol[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc]){
                    pq.push({obst+grid[nr][nc],{nr,nc}});
                    vis[nr][nc]=1;
                }
            }
        }

        return -1;
    }
};