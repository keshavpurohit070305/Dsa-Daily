class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> result;
        
        for (int i = 0; i < words.size(); i++) {
            string currentWord = words[i];
            bool foundChar = false;
            
            for (int j = 0; j < currentWord.length(); j++) {
                char currentChar = currentWord[j];
                if (currentChar == x) {
                    foundChar = true;
                    break;
                }
            }
            
            if (foundChar) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};