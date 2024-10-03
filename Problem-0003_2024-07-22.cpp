// Runtime: 137ms | 8.27%
// Memory:  10.20MB | 93.70%

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        char charactersUsed[256] {0};
        int maxCount {1};

        if (s.empty()) {
            return 0;
        }

        // Loop 1: For each character i of string s, check for longest substring
        for (int i {0}; i < s.size(); ++i) {
            charactersUsed[0] = s[i];
            
            // Loop 2: For each character j after i, check characters i through j for repeats 
            for (int j {1}; j < s.size() - i; ++j) {
                bool breakLoop {false};
                
                // Loop 3: Check for repeats
                for (int k {0}; k < j; ++k) {
                    if (charactersUsed[k] == s[i + j]) {
                        breakLoop = true;
                        break;
                    }
                }
                if (breakLoop) {
                    break;
                }
                charactersUsed[j] = s[i + j];
                if (j + 1 > maxCount) {
                    maxCount = j + 1;
                }
            }
        }

        return maxCount;
    }
};