class Solution {
public:
   
    bool isHammingOne(const string& a, const string& b) {
        if (a.length() != b.length()) return false;
        int diff = 0;
        for (int i = 0; i < a.length(); ++i) {
            if (a[i] != b[i]) diff++;
            if (diff > 1) return false;
        }
        return diff == 1;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1); 
        vector<int> parent(n, -1); 

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (groups[i] != groups[j] && 
                    words[i].length() == words[j].length() && 
                    isHammingOne(words[i], words[j])) {
                    
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    }
                }
            }
        }

        // Find the index of max dp value
        int maxLen = 0, lastIdx = 0;
        for (int i = 0; i < n; ++i) {
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                lastIdx = i;
            }
        }

        
        vector<string> result;
        while (lastIdx != -1) {
            result.push_back(words[lastIdx]);
            lastIdx = parent[lastIdx];
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
