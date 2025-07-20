class Solution {
public:
    // TC --> O(logn) to the base 10
    // SC --> O(1)
    int subtractProductAndSum(int n) {

        int sum = 0, product = 1;
        while (n > 0) {
            int lastDigit = n % 10;
            sum += lastDigit;
            product *= lastDigit;
            n = n / 10;
        }

        return product - sum;
    }
};
