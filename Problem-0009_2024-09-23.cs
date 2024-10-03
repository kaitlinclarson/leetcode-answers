// Runtime: 50ms | 47.69%
// Memory:  32.2MB | 61.74%

public class Solution {
    public bool IsPalindrome(int x) {
        int y;
        int length = 0;
        int[] array;

        if (x < 0) {
            return false;
        } else if (x < 10) {
            return true;
        }

        y = x;
        while (y > 0) {
            y /= 10;
            length++;
        }

        array = new int[length];
        y = x;
        length -= 1;
        while (y > 9) {
            array[length] = y % 10;
            y /= 10;
            --length;
        }
        array[length] = y;

        length = array.Length - 1;
        y = 0;
        while (length >= 0) {
            int length2 = length;
            int e = 1;
            while (length2 > 0) {
                length2--;
                e *= 10;
            }
            y += array[length] * e;
            length--;
        }

        if (x == y) {
            return true;
        }

        return false;
    }
}