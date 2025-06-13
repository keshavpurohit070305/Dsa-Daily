class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;       // count of unmatched '('
        int insertions = 0; // number of insertions needed

        for (char c : s) {
            if (c == '(') {
                open++; // expecting a ')'
            } else { // it's ')'
                if (open > 0) {
                    open--; // match with previous '('
                } else {
                    insertions++; // need to insert '('
                }
            }
        }

        // add unmatched '(' that still need closing ')'
        return insertions + open;
    }
};
