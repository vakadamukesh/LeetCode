class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto& it: flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> arr(n, INT_MAX);
        arr[src] = 0;
        queue<pair<int, pair<int, int>>> q;
        q.push({src, {0, 0}});
        int mini = INT_MAX;
        while(!q.empty()){
            int m = q.front().first;
            int l = q.front().second.first;
            int p = q.front().second.second;
            q.pop();
            for(auto& it: adj[m]){
                if((p + it.second < arr[it.first]) && k>=l){
                    arr[it.first] = p + it.second;
                    q.push({it.first, {l+1, p+it.second}});
                }
            }
        }
        if(arr[dst] >= INT_MAX)
            return -1;
        return arr[dst];
    }
};