class Solution {
public:
    int dp[1025][100];
    bool isValid(int mask, int maskToBeTaken, int available, vector<int>& quantity) {
        // We dont fill whats already filled
        if((mask & maskToBeTaken) != 0) return false;

        int sum = 0;
        for(int i=0;i<quantity.size();i++) {
            if((1<<i)&maskToBeTaken) sum += quantity[i];
        }

        return available>=sum;
    }
    bool recurse(vector<int>& freqNums, int mask, vector<int>& quantity, int idx) {
        if(mask == (1<<quantity.size()) -1) return true;

        if(idx >= freqNums.size()){
            return false;
        }
        
        if(dp[mask][idx]!=-1){
            return dp[mask][idx];
        }

        bool ans=false;

        for(int i=0;i<(1<<quantity.size());i++) {
            if(isValid(mask, i, freqNums[idx], quantity)) {
                ans = ans |recurse(freqNums, mask | i, quantity, idx+1);
            }
        }
        return dp[mask][idx] = ans;

    }
    vector<int> reformat(vector<int>& nums){
        map<int,int> mp;
        for(auto el:nums){
            mp[el]++;
        }
        vector<int> res;
        for(auto el:mp){
            res.push_back(el.second);
        }
        return res;
    }
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        vector<int> freqNums = reformat(nums);
        memset(dp,-1,sizeof(dp));
        return recurse(freqNums, 0, quantity, 0);
    }
};

// 9 8
// 8 5 4
// existingBitset = 0 1 1
//                  1 0 0
// currRecursion (1) =  0 0 0 to 1 1 1