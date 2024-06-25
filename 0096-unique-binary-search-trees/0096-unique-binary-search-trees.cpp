class Solution {
public:

    // top Down
    // vector<int> dp;
    // int helper(int n){
    //     if(n==0 || n==1) return 1;
    //     if(n==2) return 2;
    //     if(dp[n]!=-1) return dp[n];
    //     int ans = 0;
        
    //     for(int i=1; i<=n; i++){
    //         ans = ans + helper(i-1)*helper(n-i);
    //     }
    //     return dp[n] = ans;
    // }


    // Bottom Up

    static int helper2(int N){
        int dp[20];
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;

        for(int n=3; n<=N; n++){
            int ans = 0;
        
            for(int i=1; i<=n; i++){
            ans = ans + dp[i-1]*dp[n-i];
            }
            dp[n] = ans;
        }
        return dp[N];
    }
    
    int numTrees(int n) {
        return helper2(n);
    }
};