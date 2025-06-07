class Solution {
public:
    string clearStars(string s) {
        vector<stack<int>> letterStacks(26);
        vector<bool> isRemoved(s.length(), false);
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '*') {
                for (int j = 0; j < 26; j++) {
                    if (!letterStacks[j].empty()) {
                        int position = letterStacks[j].top();
                        letterStacks[j].pop();
                        isRemoved[position] = true;
                        break;
                    }
                }
            } else {
                letterStacks[s[i] - 'a'].push(i);
            }
        }
        
        string result = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '*' && !isRemoved[i]) {
                result += s[i];
            }
        }
        
        return result;
    }
};