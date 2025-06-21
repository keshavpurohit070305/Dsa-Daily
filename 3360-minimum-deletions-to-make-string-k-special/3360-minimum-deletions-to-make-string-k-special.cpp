class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> freq;
        for (char c : word) freq[c]++;
        vector<int> f;
        for (auto& p : freq) f.push_back(p.second);
        sort(f.begin(), f.end());
        int n = f.size(), res = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int x = f[i], del = 0;
            for (int j = 0; j < n; ++j) {
                if (f[j] < x) del += f[j];
                else if (f[j] > x + k) del += f[j] - (x + k);
            }
            res = min(res, del);
        }
        return res;
    }
};
