class Solution {
public:
    vector<int>pref, suff;
    bool can(int mid, string &t, string &s){
        //cout<<mid<<endl;
        for(int i=0, j=mid-1; j<t.size(); i++,j++){
            int a= (i==0)?0:pref[i-1];
            int b=(j==t.size()-1)?0:suff[j+1];
            //cout<<i<<"   "<<j<<"    "<<a<<"    "<<b<<endl;
            if(a==-1 || b==-1)continue;
            if(a<b)return true;
            if(j==t.size()-1 && a>=0)return true;
            if(i==0 && b>=0)return true;
        }
        return false;
    }
    void precompute(string &s, string &t){
        pref.resize(t.size(), -1);
        suff.resize(t.size(), -1);
        int n=s.size();
        for(int i=0, j=0; i<n && j<t.size(); i++){
            if(s[i]==t[j]){
                pref[j]=i;
                j++;
            }
        }
        for(int i=n-1, j=t.size()-1; i>=0 && j>=0; i--){
            if(s[i]==t[j]){
                suff[j]=i;
                j--;
            }
        }
        // for(int i=0; i<t.size(); i++){
        //     cout<<pref[i]<<"    "<<suff[i]<<endl;
        // }
    }
    int minimumScore(string s, string t) {
        precompute(s, t);
        if(suff[0]!=-1)return 0;
        int n=t.size();
        int lo=1, hi=n;
        while(hi-lo>1){
            int mid=(hi+lo)/2;
            bool c=can(mid, t, s);
            if(c){
                hi=mid;
            }else{
                lo=mid+1;
            }
        }
        if(can(lo, t, s))return lo;
        return hi;
    }
};