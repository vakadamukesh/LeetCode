class Solution {

    
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans =0, size = cardPoints.size();
        // assuming we take k elements from start of array calculate maxScore
        for(int i =0;i<k;i++){
            ans+=cardPoints[i];
        }
        int currSum = ans;
        // Now if we can pick 0 to k elements from the back and for each element we pick from back we will have to drop one element 
        // from the front array elements(in order of kth to 1st element) to keep size of ans array to k.
        for(int i =0;i<k;i++){
            currSum = currSum-cardPoints[k-i-1]+cardPoints[size-1-i];
            ans = max(ans,currSum);
        }
        return ans;
    }
};