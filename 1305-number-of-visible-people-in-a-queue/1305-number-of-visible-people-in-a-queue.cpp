class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
         int n = heights.size();
        vector<int> ans(n, 0);
        stack<int> s;
        
        for (int i = n - 1; i >= 0; --i) {
            int count = 0;
            while (!s.empty() && s.top() <= heights[i]) {
                s.pop();
                count++;
            }
            if (!s.empty()) count++;
            ans[i] = count;
            s.push(heights[i]);
        }
        
        return ans;
    }
};