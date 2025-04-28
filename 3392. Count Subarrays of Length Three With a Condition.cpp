class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int ans = 0;
        // iterating from the second element to the last second element
        for (int i = 1; i < nums.size() - 1; i++) {
            if (2 * (nums[i - 1] + nums[i + 1]) == nums[i])
                ans++;
        }
        return ans;
    }
};
