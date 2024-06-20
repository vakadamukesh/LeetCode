class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int sum=0;

        for(int i=0;i<31;i++){
            int count=0;
            //for loop for transversing in array to get the bit count at particular ith index
            for(auto j:nums){
                if(j & (1<<i)) count++; //1 is right shifted ith time from right to get the position to do 'AND' operation with 1.
            }
            // here if count>k means total number of 1 in ith position is >k then set that index as 1 or we can say add the 2^i in sum. both thing are same
            if(count>=k) sum+=pow(2,i); // as 111 is 7 as 2^0+2^1+2^2 are same
        }
        //return the final sum
        return sum;
    }
};