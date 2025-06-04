class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.length();
        
        if (numFriends == 1) {
            return word;
        }
        
        string maxStr = "";
        
        for (int i = 0; i < n; i++) {
            int maxLen = n - numFriends + 1;
            int len = min(maxLen, n - i);
            
            string substr = word.substr(i, len);
            
            if (substr > maxStr) {
                maxStr = substr;
            }
        }
        
        return maxStr;
    }
};