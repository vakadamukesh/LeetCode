class Solution {
public:
    int recurr(int i, int j, int p, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(i == matrix.size() || j == matrix[0].size() || i<0 || j<0)
            return 0;
            
        if(p != -1 && matrix[i][j] <= p)
            return 0;
            
        if(dp[i][j] != -1)
            return dp[i][j];

        int left = 1 + recurr(i, j-1, matrix[i][j], matrix, dp);
        int right = 1+recurr(i, j+1, matrix[i][j], matrix, dp);
        int up = 1+recurr(i-1, j, matrix[i][j], matrix, dp);
        int down = 1+recurr(i+1, j, matrix[i][j], matrix, dp);
        int max1 = max(left, right);
        int max2 = max(up, down);
        dp[i][j] = max(max1, max2);
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix[0].size(), m = matrix.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int path = INT_MIN;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                path = max(path, recurr(i, j, -1, matrix, dp));
            }
        }

        return path;
    }
};