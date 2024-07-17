class Solution {
public:
    int n;
    unordered_map<int,int> mp;
    int dp[2001][2001];

    int helper(int curr_stone_idx, int prevJump, vector<int>& stones){
        if(curr_stone_idx == n-1){ // frog is in last stone
            return true;
        }

        if(dp[curr_stone_idx][prevJump] != -1){
            return dp[curr_stone_idx][prevJump];
        }

        bool result = false;

        // checking for k-1, k, k+1
        for(int nextJump = prevJump - 1; nextJump <= prevJump+1; nextJump++){

            if(nextJump > 0){ // checking if jump is valid 
                int nextStone = stones[curr_stone_idx] + nextJump;

                if(mp.find(nextStone) != mp.end()){ // if next stone is present in the map
                    result |= helper(mp[nextStone], nextJump, stones);
                }
            }
        }

        return dp[curr_stone_idx][prevJump] = result;
    }

    bool canCross(vector<int>& stones) {
        n = stones.size();

        if(stones[1] != 1){ // if there is no 1 hence the frog can't jump further
           return false;
        }

        for(int i=0; i<n; i++){ // storing all the stones with thier indexes
            mp[stones[i]] = i;
        }

        memset(dp,-1,sizeof(dp));

        return helper(0, 0, stones);

    }
};