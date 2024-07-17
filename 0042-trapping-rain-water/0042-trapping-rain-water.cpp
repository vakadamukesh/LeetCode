class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
        int lm=INT_MIN;
        int rm=INT_MIN;
        int l=0,r=n-1,ans=0;
        while(l<r)
        {
            lm=max(lm,h[l]);
            rm=max(rm,h[r]);
            ans+=(lm<rm)?lm-h[l++]:rm-h[r--];
        }
        return ans;
    }
};