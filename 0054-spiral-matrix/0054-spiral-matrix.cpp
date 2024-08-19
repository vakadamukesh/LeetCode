class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return {};
        vector<int> result;
        int m=matrix.size(), n=matrix[0].size();
        int top=0,bottom=m-1,left=0,right=n-1;
        while(top<=bottom && left<=right){
            //for top row
            for(int i=left;i<=right;i++){
                result.push_back(matrix[top][i]);
            }
            top++;
            // for right column
            for(int i=top;i<=bottom;i++){
                result.push_back(matrix[i][right]);
            }
            right--;
            //for bottom row
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                    result.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            //for left column 
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return result; 
        //please upvote T_T
    }
};