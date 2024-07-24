class Solution {
public:
    
    bool canPlace (int x, int col, vector<string>& s)
    {
        int row =x;
        int column = col;
      while ( x >= 0 && col >= 0 )
      {       
        if(s[x][col]=='Q')  return false;
        x--;
        col--;      
      }
      x= row;
      col=column;
     while ( x <  s.size() && col >= 0 ){
            
            if(s[x][col]=='Q') return false;
            x++;
            col--;
            
            
        }
         x= row;
      col=column; 
       while( col >= 0 ){
          
          if (s[x][col]=='Q') return false;
          col--;
   
      }  
        return true;
    }
    
    
    void solve (int col, vector < string > s, int n , vector<vector<string>>& ans ){
        if (col == n) {
            ans.push_back(s);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (canPlace(i, col, s)) {
                s[i][col] = 'Q';
                solve(col + 1, s, n, ans);
                s[i][col] = '.';
            }
        
    }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector < string > s ( n , string (n,'.') );
        solve ( 0 ,s, n,ans );
        return ans;
    }
};

