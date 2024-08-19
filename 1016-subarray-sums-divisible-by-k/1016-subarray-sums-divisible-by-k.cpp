class Solution {
public:
    int subarraysDivByK(vector<int>& arr, int k) {
    int n = arr.size();

    vector<int> v(k+1,0);
    long int sm=0;
    for(int i=0;i<n;i++){
        sm+=arr[i];
        int rem = sm%k;
        if(rem<0)rem+=k;
        v[rem]++;
    }

    int ans=v[0];

    for(int i=0;i<k;i++){
        int tt = (v[i]*(v[i]-1))/2;
        ans+=tt;
    }
    return ans;
    }
};