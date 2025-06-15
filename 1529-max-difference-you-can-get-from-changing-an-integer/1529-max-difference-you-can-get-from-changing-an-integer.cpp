class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        int maxVal = num, minVal = num;
        for (char x = '0'; x <= '9'; ++x) {
            for (char y = '0'; y <= '9'; ++y) {
                if (x == y) continue;
                string t = s;
                for (char &c : t) {
                    if (c == x) c = y;
                }
                if (t[0] == '0') continue;
                int val = stoi(t);
                maxVal = max(maxVal, val);
                minVal = min(minVal, val);
            }
        }
        return maxVal - minVal;
    }
};
