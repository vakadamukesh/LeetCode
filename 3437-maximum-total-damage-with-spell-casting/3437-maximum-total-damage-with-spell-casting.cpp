class Solution {
    int n = 0;
    vector<long long> dp;
    long long f1(int i, vector<int>& power) {
        if (i == n) 
            return 0;
        if (dp[i] != -1) return dp[i];
        long long take = 0, notTake = 0;
        int j = i + 1, count = 1;
        while (j < n && power[j] <= power[i]+2) {
            if (power[j] == power[i]) 
                count++;
            j++;
        }
        notTake = f1(i + count, power);
        // j stores the index of first element greater than nums[i] + 2.
        take = (long long)power[i] * count + f1(j, power);
        return dp[i] = max(take, notTake);
    }
public:
    long long maximumTotalDamage(vector<int>& power) {
        sort(power.begin(), power.end());
        n = power.size();
        dp.resize(n, -1);
        return f1(0, power);
    }
};