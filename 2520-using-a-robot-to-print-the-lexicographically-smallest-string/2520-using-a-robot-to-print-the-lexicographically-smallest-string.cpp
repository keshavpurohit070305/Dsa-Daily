class Solution {
public:
    string robotWithString(string s) {
        string t, p;
        vector<int> freq(26);
        for (char c : s) freq[c - 'a']++;
        int minChar = 0;
        for (char c : s) {
            t += c;
            freq[c - 'a']--;
            while (minChar < 26 && freq[minChar] == 0) minChar++;
            while (!t.empty() && t.back() - 'a' <= minChar) {
                p += t.back();
                t.pop_back();
            }
        }
        return p;
    }
};
