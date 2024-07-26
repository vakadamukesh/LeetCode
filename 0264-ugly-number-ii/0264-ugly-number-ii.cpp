class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==1)
        return 1;
        vector<int>u(n+1);
        u[1]=1;
        int i2=1,i3=1,i5=1;
        for(int i=2;i<=n;i++)
        {
            int i22=u[i2]*2;
            int i33=u[i3]*3;
            int i55=u[i5]*5;
            int mi=min({i22,i33,i55});
            u[i]=mi;
            if(mi==i22)
            i2++;
            if(mi==i33)
            i3++;
            if(mi==i55)
            i5++;
        }
        return u[n];
    }
};