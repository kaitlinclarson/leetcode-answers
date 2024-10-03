// Runtime: 14ms | 74.6%
// Memory:  8.4MB | 80.59%

class Solution {
public:
    string longestPalindrome(string s) {
        int bestIndex {0};
        int bestLength {1};

        if (s.empty()) {
            return "";
        } else if (s.size() == 1) {
            return s;
        }

        // For each letter in s:
        for (int i = 1; i < s.size(); ++i) {
            // For each letter after letter i,
            // try to make a palindrome from the center letter
            
            // Case for palindromes of odd length
            for (int j = 1; (i - j >= 0) && (i + j < s.size()); ++j) {
                if (s[i - j] != s[i + j]) {
                    // Check if last valid string is best
                    if ((j - 1) * 2 + 1 > bestLength) {
                        bestLength = (j - 1) * 2 + 1;
                        bestIndex = i - (j - 1);
                    }
                    break;
                }
                // Successful to end of string: check if best
                if ((i + j == s.size() - 1) || (i - j == 0)) {
                    if (j * 2 + 1 > bestLength) {
                        bestLength = j * 2 + 1;
                        bestIndex = i - j;
                    }
                }
            }

            // Case for palindromes of even length
            for (int j = 1; (i - j >= 0) && (i + j - 1 < s.size()); ++j) {
                if (s[i - j] != s[i + j - 1]) {
                    // Check if last valid string is best
                    if ((j - 1) * 2 > bestLength) {
                        bestLength = (j - 1) * 2;
                        bestIndex = i - (j - 1);
                    }
                    break;
                }
                // Successful to end of string: check if best
                if ((j + i - 1 == s.size() - 1) || (i - j == 0)) {
                    if (j * 2 > bestLength) {
                        bestLength = j * 2;
                        bestIndex = i - j;
                    }
                }
            }
        }

        return s.substr(bestIndex, bestLength);
    }
};