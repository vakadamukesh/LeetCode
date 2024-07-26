class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;

        for(auto c: s)
        {
          mp[c]++;
        }

        priority_queue<pair <int, char>> hp;//heap decearation

        for(auto entry: mp)
        {
          hp.push({entry.second, entry.first});
        }

        string res = "";
        while(hp.size() > 1)
        {
          //Exatract two top elements
            auto one = hp.top();
                    hp.pop();
            auto two = hp.top();
                    hp.pop();

            //store it
            res += one.second;
            res += two.second;
            //cout<<res;
  
            //Now reduce the frequency
            one.first -= 1;
            two.first -= 1;

            if(one.first > 0)
              hp.push(one);
            if(two.first > 0)
              hp.push(two);
            //cout<<res;

        }

        // Handling the last character if it is odd
        if(!hp.empty())
        {
          if(hp.top().first > 1)
          {
            return "";
          }
          else
          {
            res += hp.top().second;
          }
          
        }


        return res;
    }
};