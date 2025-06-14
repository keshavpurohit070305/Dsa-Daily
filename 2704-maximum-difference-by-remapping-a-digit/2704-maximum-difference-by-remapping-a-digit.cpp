class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string maxStr = s, minStr = s;
        
        for (char d = '0'; d <= '9'; d++) {
            for (char r = '0'; r <= '9'; r++) {
                string t = s;
                for (char& c : t) {
                    if (c == d) c = r;
                }
                if (t[0] != '0') {
                    maxStr = max(maxStr, t);
                    minStr = min(minStr, t);
                } else {
                    minStr = min(minStr, t);
                }
            }
        }
        
        return stoi(maxStr) - stoi(minStr);
    }
};
