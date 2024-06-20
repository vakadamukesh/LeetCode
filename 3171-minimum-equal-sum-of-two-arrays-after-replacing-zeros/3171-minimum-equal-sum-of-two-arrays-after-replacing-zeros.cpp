#define ll long long int
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        ll zeroC1=0,zeroC2=0;
        ll sum1=0,sum2=0;
        for(auto e:nums1){
            if(e==0) zeroC1++;
            sum1+=e;
        }
        for(auto e:nums2){
            if(e==0) zeroC2++;
            sum2+=e;
        }
        
        if(zeroC1==0 && sum1<sum2+zeroC2)  return -1;
        if(zeroC2==0 && sum2<sum1+zeroC1)  return -1;
        return max(sum1+zeroC1,sum2+zeroC2);
    }
};