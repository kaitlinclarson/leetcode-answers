// Runtime: 57ms | 43.79%
// Memory:  39.29MB | 85.45%

public class Solution {
    public bool IsValid(string s) {
        Stack<char> chars = new Stack<char>();

        for (int i = 0; i < s.Length; i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                chars.Push(s[i]);
            } else {
                if (chars.Count == 0) {
                    return false;
                }
                char c = chars.Pop();
                if (s[i] == ')' && c != '(') {
                    return false;
                } else if (s[i] == ']' && c != '[') {
                    return false;
                } else if (s[i] == '}' && c != '{') {
                    return false;
                }
            }
        }

        if (chars.Count > 0) {
            return false;
        }

        return true;
    }
}