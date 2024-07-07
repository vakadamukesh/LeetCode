class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        for(int i=0;i<k-1;i++){
            colors.push_back(colors[i]);
        }
        int n=colors.size();
        vector<int>ind(n,0);
        for(int i=0;i<(n-1);i++){
            if(colors[i]==colors[(i+1)]){
                ind[i]++;
            }
        }
        for(int i=1;i<n;i++){
            ind[i]+=ind[i-1];
        }
        int c=0;
        for(int i=0;i<=(n-k);i++){
            int j=i+k-2;
            int diff=0;
            if(i==0){
                diff=ind[j];
            }
            else{
                diff=ind[j]-ind[i-1];
            }
            if(diff==0)c++;
        }
        return c;
    }
};