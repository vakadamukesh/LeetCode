class Solution {
public:
    int start = 0 , end = 0 , mid ,ans = 0 ;

    bool isValid (vector<int>& nums, int k){
        int sum = 0 , student = 1 ;

        for ( int i = 0 ; i < nums.size() ; i++ ){

            if(sum + nums[i] <= mid ) sum += nums[i] ;

            else {
                student++ ;
                sum = nums[i] ; 
                if ( student > k || nums[i] > mid ) return false ;
            }
        }
        return true ;
    }
    int splitArray(vector<int>& nums, int k) {
        

        for ( int i = 0 ; i < nums.size() ; i++ ){
            end = end + nums[i] ; 
        }

        while ( start <= end ) {

            mid = start + ( end - start ) / 2 ;

            if ( isValid( nums , k ) ) {
                end = mid - 1 ;
                ans = mid ;
            }

            else {
                start = mid + 1 ;
            }

            
        }

        return ans;
    }
};