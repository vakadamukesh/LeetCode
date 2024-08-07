class Solution {
public:
    // the whole process is exact same as merge sort and cnt inversions 
    // just a little change in counting is there
    int merge(vector<int> &nums,int low,int mid,int high){
        int total=0;
        int j=mid+1;
        for(int i=low;i<=mid;i++){
            while(j<=high && (long)nums[i]>(long)2*nums[j]) j++;
            // STEP3
            // this will cnt the possible pairs 
            total+=j-(mid+1);
        }
        // STEP4
        // this is to merge the array
        vector<int> t;
        int left=low,right=mid+1;
        while(left<=mid && right<=high){
            if(nums[left]<=nums[right]){
                t.push_back(nums[left]);
                left++;
            }
            else{
                t.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid){
            t.push_back(nums[left]);
            left++;
        }
        while(right<=high){
            t.push_back(nums[right]);
            right++;
        }
        for(int i=low;i<=high;i++){
            nums[i]=t[i-low];
        }
        return total;
    }
    int mergesort(vector<int> &nums,int low, int high){
        if(low>=high) return 0;
        int mid=(low+high)/2;
        // STEP2 
        // cnt all the possible pairs 
        int cnt=0;
        cnt+=mergesort(nums,low,mid);
        cnt+=mergesort(nums,mid+1,high);
        cnt+=merge(nums,low,mid,high);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        // STEP1
        // apply merge sort on whole array
        return mergesort(nums,0,nums.size()-1);
    }
};