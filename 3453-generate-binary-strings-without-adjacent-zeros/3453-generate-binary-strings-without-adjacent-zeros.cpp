class Solution {
public:
    void backtrack(int n, string& current, vector<string>& result) {
        if (current.length() == n) {
            result.push_back(current);
            return;
        }
        
        // If the string is empty or the last character is '1', we can add either '0' or '1'
        if (current.empty() || current.back() == '1') {
            current.push_back('0');
            backtrack(n, current, result);
            current.pop_back();
            
            current.push_back('1');
            backtrack(n, current, result);
            current.pop_back();
        }
        // If the last character is '0', we must add '1' to maintain validity
        else {
            current.push_back('1');
            backtrack(n, current, result);
            current.pop_back();
        }
    }
    
    vector<string> validStrings(int n) {
        vector<string> result;
        string current;
        backtrack(n, current, result);
        return result;
    }
};