class Solution {
    private:
    string processString( string& str){
        stack<char>editor;
        for(auto&c : str){
            if(c != '#'){
                editor.push(c);
            }else if (!editor.empty()){// c=='#' so we are removing the letter bcoz backspace
                editor.pop();
            }
        }
        string result;
        while(!editor.empty()){
            result += editor.top();
            editor.pop();
        }
       
        return result;
    }
public:
    bool backspaceCompare(string s, string t) {
        return processString(s) == processString(t);
    }
};