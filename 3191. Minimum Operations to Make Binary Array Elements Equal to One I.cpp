class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();

        for (int i = 0; i <= n - 3; i++) {
            if (nums[i] == 0) {
                // Perform the flip operation
                for (int j = i; j <= i + 2; j++) {
                    nums[j] = 1 - nums[j]; // Flip 0 to 1 and 1 to 0
                }
                ans++;
            }
        }

        // Check if all elements are 1
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                return -1;
            }
        }
        return ans;
    }
};
