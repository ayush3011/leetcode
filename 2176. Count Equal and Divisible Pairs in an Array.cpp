class Solution {
public:
    // Brute Force : TC - O(n^2)
    int countPairs(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((nums[i] == nums[j]) && ((i * j) % k == 0)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
