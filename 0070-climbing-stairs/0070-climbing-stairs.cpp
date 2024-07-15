class Solution {
public:
    int climbStairs(int n) {
        if(n==1)
        return 1;
        if(n==2)
        return 2;
        int a=1;
        int b=2;
        for(int i=3;i<=n;i++)
        {
            int k=(a+b);
            a=b;
            b=k;
        }
        return b;
    }
};