class Solution {
public:
    int maximumGain(string s, int x, int y) {
        vector<char> v1,v2;
        int flag;
        if(x>y) flag = 1;
        else flag = 0;
        int ans = 0;
            for(auto c : s ){
                if(!v1.empty()){
                    if(flag){
                        if(v1.back() == 'a' && c == 'b') ans+=x , v1.pop_back();
                        else v1.push_back(c);
                    }
                    else{
                        if(v1.back() == 'b' && c == 'a') ans+=y , v1.pop_back();
                        else v1.push_back(c);
                    }
                }
                else v1.push_back(c);
            }

            for(auto c : v1){
                if(!v2.empty()){
                    if(!flag){
                        if(v2.back() == 'a' && c == 'b') ans+=x , v2.pop_back();
                        else v2.push_back(c);
                        }
                    else{
                        if(v2.back() == 'b' && c == 'a') ans+=y , v2.pop_back();
                        else v2.push_back(c);
                    }
                    }
                else v2.push_back(c);
                }
            return ans;
            }
};