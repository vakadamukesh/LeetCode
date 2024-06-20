// Author : @itsyeshu
class Solution {
private:
    int dfs(int i, int parent, int k, int t, const vector<int> &coins, const vector<vector<int>>& adj, int memo[][14]) {
        if (t >= 14)
            return 0;
        if (memo[i][t] >= 0)
            return memo[i][t];
        int case1 = (coins[i] >> t) - k, case2 = coins[i] >> (t+1);
        for (int j : adj[i]) {
            if (j != parent) {
                case1 += dfs(j, i, k, t, coins, adj, memo);
                case2 += dfs(j, i, k, t + 1, coins, adj, memo);
            }
        }
        return memo[i][t] = max(case1, case2);
    }

public:
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        int n = coins.size();
        vector<vector<int>> adj(n);
        for(vector<int>& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int memo[n][14];
        memset(memo, -1, sizeof(memo));
        return dfs(0, -1, k, 0, coins, adj, memo);
    }
};