class Solution {
public:
    long long kMirror(int k, int n) {
        long long sum = 0;
        int count = 0;
        
        for (int len = 1; count < n; len++) {
            vector<long long> palindromes = generatePalindromes(len);
            
            for (long long palindrome : palindromes) {
                if (count >= n) break;
                
                if (isPalindrome(palindrome, k)) {
                    sum += palindrome;
                    count++;
                }
            }
        }
        
        return sum;
    }
    
private:
    vector<long long> generatePalindromes(int len) {
        vector<long long> result;
        
        if (len == 1) {
            for (int i = 1; i <= 9; i++) {
                result.push_back(i);
            }
            return result;
        }
        
        bool isOdd = len % 2 == 1;
        int halfLen = (len + 1) / 2;
        long long start = 1;
        for (int i = 1; i < halfLen; i++) start *= 10;
        long long end = start * 10 - 1;
        
        for (long long i = start; i <= end; i++) {
            long long palindrome = i;
            long long temp = isOdd ? i / 10 : i;
            
            while (temp > 0) {
                palindrome = palindrome * 10 + temp % 10;
                temp /= 10;
            }
            
            result.push_back(palindrome);
        }
        
        return result;
    }
    
    bool isPalindrome(long long num, int k) {
        vector<int> digits;
        long long temp = num;
        
        while (temp > 0) {
            digits.push_back(temp % k);
            temp /= k;
        }
        
        int left = 0, right = digits.size() - 1;
        while (left < right) {
            if (digits[left] != digits[right]) return false;
            left++;
            right--;
        }
        
        return true;
    }
};