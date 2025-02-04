class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ansSum = nums[0];   // for storing the max possible sum
        int localSum = nums[0]; // for storing ascending subarray sum
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                localSum += nums[i];
            } else {
                ansSum = max(ansSum, localSum);
                localSum = nums[i];
            }
        }
        return max(ansSum, localSum);
    }
};
