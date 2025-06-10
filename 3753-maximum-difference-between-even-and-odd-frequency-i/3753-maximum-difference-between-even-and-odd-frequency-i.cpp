class Solution {
public:
    int maxDifference(string s) {
        // Count frequency of each character
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        
        int maxOdd = 0;
        int minEven = INT_MAX;
        
        // Find maximum odd frequency and minimum even frequency
        for (auto& p : freq) {
            if (p.second % 2 == 1) {  // Odd frequency
                maxOdd = max(maxOdd, p.second);
            } else {  // Even frequency
                minEven = min(minEven, p.second);
            }
        }
        
        return maxOdd - minEven;
    }
};