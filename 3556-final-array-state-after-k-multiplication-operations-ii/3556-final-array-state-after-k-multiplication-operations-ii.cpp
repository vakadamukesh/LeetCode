#define ll long long
class Solution {
public:
   
    long long mod_inv(long long a,long long n,long long p)
    {   long long res=1;
        while(n)
        { if(n%2)
            {
                res=(res*a)%p;
                n--;
            }
            else
            {
                a=(a*a)%p;
                n/=2;
            }
        }
        return res;
    }

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) 
    {   
        if(multiplier==1)
        {
            return nums;
        } 
        ll mod=1000000007;
        int n=nums.size();
        set<pair<ll,int>>st;
        vector<pair<ll,int>>vp; 
        for(int i=0;i<nums.size();i++)
        {
            st.insert({nums[i],i});
        }
        while(k)
        {
            auto firstit=st.begin();
            auto lastit=st.end();
            lastit--;
            if(((*firstit).first*multiplier)>(*lastit).first)
            {
                break;
            }
            else
            {  
                ll ind=(*firstit).second;
                ll val=((*firstit).first*multiplier)%mod;
                st.erase(firstit);
                st.insert({val,ind});
            }
            k--;
        }
        for(auto it=st.begin();it!=st.end();it++)
        {
            vp.push_back(*it);
            
        }
       
        for(int i=0;i<vp.size();i++)
        {
            ll value=mod_inv(multiplier,k/n,mod)%mod;
            vp[i].first=((vp[i].first*value)%mod);
        }
        int extra=k%n;
        for(int i=0;i<extra;i++)
        {
            vp[i].first=((vp[i].first*multiplier)%mod);
        }
        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
        {
            ans[vp[i].second]=vp[i].first;
        }
        return ans;
    }
};