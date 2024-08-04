class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>adj[600];
        for(int i=0;i<n-1;i++)
        {
            vector<int>a;
            a.push_back(i+1);
            a.push_back(1);
            adj[i].push_back(a);
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int>ans;
        
       
        for(int i=0;i<queries.size();i++)
        {
             vector<int>a;
            a.push_back(queries[i][1]);
            a.push_back(1);
            adj[queries[i][0]].push_back(a);
            a.clear();
            vector<int> dist(n,INT_MAX);
             dist[0]=0;
             pq.push({0,0});
        while(pq.empty()==false)
        {
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for (auto it:adj[node])
            {
                int edge_weight=it[1];
                int adjNode=it[0];
                if (dis+edge_weight<dist[adjNode])
                {
                    dist[adjNode]=dis+edge_weight;
                    pq.push({dis+edge_weight,adjNode});
                }
            }
        }
        ans.push_back(dist[n-1]);
        }
        return ans;

    }
};