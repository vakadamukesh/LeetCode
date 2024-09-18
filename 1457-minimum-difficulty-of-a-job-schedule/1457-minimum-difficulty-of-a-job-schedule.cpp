class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int sz = jobDifficulty.size();
        if (d > sz) return -1;
        vector<vector<int>> dp(sz + 1, vector<int>(d+1, 1e5));
        dp[sz-1][1] = jobDifficulty[sz-1];
        for(int i = sz - 2; i >= 0; i--) dp[i][1] = max(dp[i+1][1], jobDifficulty[i]);
        for (int j = 2; j <= d; j++){
            for (int i = sz - j; i >= 0; i--){
                int maxValue = jobDifficulty[i];
                for (int k = i; k <= sz - j; k++){
                    maxValue = max(maxValue, jobDifficulty[k]);
                    dp[i][j] = min(dp[i][j], maxValue + dp[k+1][j-1]);
                }
            }
        }
        return dp[0][d];
    }
};