class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        while (s.length() < k) {
            string temp = "";
            for (char c : s) {
                temp += (c == 'z' ? 'a' : c + 1);
            }
            s += temp;
        }
        return s[k - 1];
    }
};
