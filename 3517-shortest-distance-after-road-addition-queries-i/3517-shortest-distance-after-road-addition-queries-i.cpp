class Solution {
public:
    int dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int>dist(V,INT_MAX);
        dist[S]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,S});
        while(!pq.empty()){
            int topdist=pq.top().first;
            int topnode=pq.top().second;
            pq.pop();
            for(auto it:adj[topnode]){
                int d=topdist+it[1];
                if(d<dist[it[0]]){
                    dist[it[0]]=d;
                    pq.push({d,it[0]});
                }
            }
        }
        return dist[V-1];
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj[n];
        for(int i=0;i<n-1;i++){
            adj[i].push_back({i+1,1});
        }
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            adj[queries[i][0]].push_back({queries[i][1],1});
            ans.push_back((dijkstra(n,adj,0)));
        }
        return ans;
    }
};