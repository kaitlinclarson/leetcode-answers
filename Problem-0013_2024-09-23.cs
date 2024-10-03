// Runtime: 53ms | 61.73%
// Memory:  48.87MB | 70.27%

public class Solution {
    private Dictionary<char, int> dict = 
        new Dictionary<char, int>{
            { 'I', 1 },
            { 'V', 5 },
            { 'X', 10 },
            { 'L', 50 },
            { 'C', 100 },
            { 'D', 500 },
            { 'M', 1000 }
        };

    public int RomanToInt(string s) {
        int value = 0;
        for (int i = 0; i < s.Length; i++) {
            char c = s[i];
            if (i < s.Length - 1) {
                if (c == 'I') {
                    if (s[i + 1] == 'V') {
                        i++;
                        value += 4;
                        continue;
                    } else if (s[i + 1] == 'X') {
                        i++;
                        value += 9;
                        continue;
                    }
                } else if (c == 'X') {
                    if (s[i + 1] == 'L') {
                        i++;
                        value += 40;
                        continue;
                    } else if (s[i + 1] == 'C') {
                        i++;
                        value += 90;
                        continue;
                    }
                } else if (c == 'C') {
                    if (s[i + 1] == 'D') {
                        i++;
                        value += 400;
                        continue;
                    } else if (s[i + 1] == 'M') {
                        i++;
                        value += 900;
                        continue;
                    }
                }
            }
            value += dict[c];
        };
        return value;
    }
}