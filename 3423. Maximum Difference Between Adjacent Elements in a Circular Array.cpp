class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxDiff = INT_MIN;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            int currDiff = abs(nums[i] - nums[i + 1]);
            maxDiff = max(maxDiff, currDiff);
        }
        if (abs(nums[n - 1] - nums[0]) > maxDiff)
            maxDiff = abs(nums[n - 1] - nums[0]);
        return maxDiff;
    }
};
