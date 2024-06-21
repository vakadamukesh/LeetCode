class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int result = k;
        
        unordered_map<char, int> mp;

        int i = 0;
        for (int j = 0; j < answerKey.length(); j++) {

            mp[answerKey[j]]++;
            
            while (min(mp['T'], mp['F']) > k) {
                mp[answerKey[i]]--;
                i++;
            }
            
            result = max(result, j - i + 1);
        }
        
        return result;
    }
};