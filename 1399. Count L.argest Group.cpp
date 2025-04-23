class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            int lastDigit = n % 10;
            n = n / 10;
            sum += lastDigit;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        int ans = 0;
        int maxCount = 0;
        unordered_map<int, int> m;

        for (int i = 1; i <= n; i++) {
            int sum = digitSum(i);
            m[sum]++;
            maxCount = max(maxCount, m[sum]);
        }

        for (auto it : m) {
            if (it.second == maxCount) {
                ans++;
            }
        }

        return ans;
    }
};
