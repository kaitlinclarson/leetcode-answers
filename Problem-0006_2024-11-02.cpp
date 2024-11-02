// 6. Zigzag Conversion
// Runtime: 4ms | 71.54%
// Memory:  10.60MB | 92.64%

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 0) return ""; // No rows means no string
        if (numRows == 1) return s; // Single row is the original string
        
        string val = "";

        // Top row
        for (int i = 0; i < s.length(); i += 2 * (numRows - 1))
            val += s[i];
        
        // Middle rows
        bool alt;
        for (int x = 1; x < numRows - 1; ++x) {
            // The next index for the middle row characters alternate
            alt = false;
            for (int i = x; i < s.length(); i += (alt ? (numRows - x - 1) * 2 : x * 2)) {
                val += s[i];
                alt = !alt;
            }
        }

        // Bottom row
        for (int i = numRows - 1; i < s.length(); i += 2 * (numRows - 1))
            val += s[i];

        return val;
    }
};