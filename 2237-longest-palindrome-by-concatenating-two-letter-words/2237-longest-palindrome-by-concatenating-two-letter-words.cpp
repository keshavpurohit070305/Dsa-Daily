class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> wordCount;
        int totalLength = 0;
        bool centerUsed = false;

        for (const string& word : words) {
            wordCount[word]++;
        }

        for (auto& [word, count] : wordCount) {
            string reversed = string{word.rbegin(), word.rend()};

            if (word == reversed) {
              
                int pairs = count / 2;
                totalLength += pairs * 4;
                wordCount[word] -= pairs * 2;
                if (!centerUsed && wordCount[word] > 0) {
                    totalLength += 2;
                    centerUsed = true;
                }
            } else if (wordCount.find(reversed) != wordCount.end()) {
                int match = min(wordCount[word], wordCount[reversed]);
                totalLength += match * 4;
                wordCount[word] -= match;
                wordCount[reversed] -= match;
            }
        }

        return totalLength;
    }
};
