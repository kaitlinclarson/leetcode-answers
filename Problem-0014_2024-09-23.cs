// Runtime: 72ms | 40.68%
// Memory:  41.98MB | 89.62%

public class Solution {
    public string LongestCommonPrefix(string[] strs) {
        if (strs.Length == 0) {
            return "";
        }

        string prefix = strs[0];
        foreach (string s in strs) {
            for (int i = 0; i < prefix.Length; i++) {
                if (i >= s.Length) {
                    prefix = prefix.Substring(0, i);
                } else if (prefix[i] != s[i]) {
                    prefix = prefix.Substring(0, i);
                }
            }
        }

        return prefix;
    }
}