class Solution {
public:
    int countDigits(int n) {
        int digits = 0;
        while (n > 0) {
            n = n / 10;
            digits++;
        }
        return digits;
    }
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for (int n : nums) {
            int digit = countDigits(n);
            if (digit % 2 == 0)
                ans++;
        }
        return ans;
    }
};
