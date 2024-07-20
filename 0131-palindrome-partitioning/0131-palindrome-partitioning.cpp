class Solution {
private:
    bool isPalindrome(string st){
        int s=0,e=st.size()-1;
        while(s<=e){
            if(st[s++]!=st[e--])
                return false;
        }
        return true;
    }

    void f(vector<vector<string>>&ans,vector<string>&temp,string str,int ind){
        if(ind==str.size()){
            ans.push_back(temp);
            return;
        }
        string x="";
        for(int i=ind;i<str.size();i++){
            x+=str[i];
            if(isPalindrome(x)){
                temp.push_back(x);
                f(ans,temp,str,i+1);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        f(ans,temp,s,0);
        return ans;
    }
};