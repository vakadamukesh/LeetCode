class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int min_row = INT_MAX;
        int max_row = INT_MIN;
        int min_col = INT_MAX;
        int max_col = INT_MIN;
        
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    min_row = min(min_row, i);
                    max_row = max(max_row, i);
                    min_col = min(min_col, j);
                    max_col = max(max_col, j);
                }
            }
        }
        
        int height = max_row - min_row + 1;
        int width = max_col - min_col + 1;
        
        return height * width;
    }
};