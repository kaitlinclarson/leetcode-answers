// 7. Reverse Integer
// Runtime: 3ms | 29.57%
// Memory:  8.50MB | 7.09%

class Solution {
public:
    int reverse(int x) {
        int digits[10];
        int digitCount = 0;
        int returnValue = 0;
        bool negative = x < 0;
        bool carry = false;

        if (negative) {
            if (x == -2147483648) {
                x += 1;
                carry = true;
            }
            x *= -1;
        }

        while (x > 9) {
            digits[digitCount] = x - ((x / 10) * 10);
            x /= 10;
            ++digitCount;
        }
        digits[digitCount] = x;
        ++digitCount;

        int maxes[10] = {2, 1, 4, 7, 4, 8, 3, 6, 4, 7};
        if (digitCount > 9) {
            for (int i = 0; i < digitCount; i++) {
                // If the next digit is over the corresponding max,
                // the number exceeds the limit and must return 0.
                if (digits[i] > maxes[i])
                    return 0;
                // If the next digit is under the limit,
                // the next digits are safe and the for loop can end.
                else if (digits[i] < maxes[i])
                    break;
            }
        }

        for (int j = 0; j < digitCount; ++j) {
            int exponent = digitCount - j - 1;
            int temp = digits[j];
            while (exponent > 0) {
                temp *= 10;
                --exponent;
            }
            returnValue += temp;
        }

        if (negative)
            returnValue = returnValue * -1 + (carry ? -1 : 0);

        return returnValue;
    }
};