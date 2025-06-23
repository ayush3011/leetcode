class Solution {
public:
    // Function to check if a string is a palindrome
    bool isPalindrome(string baseK) {
        int i = 0;
        int j = baseK.length() - 1;

        while (i <= j) {
            if (baseK[i] != baseK[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    // Function to convert a decimal number to base-k representation
    string convertToBaseK(long long num, int k) {
        if (num == 0) {
            return "0";
        }
        string res = "";
        while (num > 0) {
            res += to_string(num % k); // Append remainder (digit in base-k)
            num /= k;
        }
        return res; // Note: digits are in reverse order
    }

    // Function to find the sum of first n numbers which are palindromes in both
    // base-10 and base-k
    long long kMirror(int k, int n) {
        long long sum = 0;
        int L = 1; // Length of palindrome numbers to be generated

        while (n > 0) {
            int halfLength =
                (L + 1) / 2; // Number of digits needed to form first half

            // Generate numbers with 'halfLength' digits (e.g., for L=3,
            // halfLength=2 ⇒ 10 to 99)
            long long minNum = pow(10, halfLength - 1);
            long long maxNum = pow(10, halfLength) - 1;

            for (int num = minNum; num <= maxNum; num++) {
                string firstHalf = to_string(num);
                string secondHalf = firstHalf;
                reverse(
                    begin(secondHalf),
                    end(secondHalf)); // Prepare the second half for palindrome

                string pal = "";
                if (L % 2 == 0) {
                    pal = firstHalf +
                          secondHalf; // Even length: mirror full first half
                } else {
                    pal = firstHalf +
                          secondHalf.substr(1); // Odd length: skip middle digit
                }

                long long palNum =
                    stoll(pal); // Convert palindrome string to number

                string baseK = convertToBaseK(palNum, k); // Convert to base-k

                if (isPalindrome(baseK)) { // Check if base-k representation is
                                           // also palindrome
                    sum += palNum;         // Add to result
                    n--;                   // One valid number found
                    if (n == 0) {
                        break; // Stop once we have found n numbers
                    }
                }
            }
            L++; // Move to next palindrome length
        }
        return sum;
    }
};
