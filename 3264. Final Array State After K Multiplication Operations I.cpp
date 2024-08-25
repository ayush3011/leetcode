class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        while (k--) { // running the loop k times
            int minValue = INT_MAX, minValueIndex; 
            for (int i = 0; i < n; i++) { // each time finding the min value in the array and its index
                if (nums[i] < minValue) {
                    minValue = nums[i];
                    minValueIndex = i;
                }
            }
            nums[minValueIndex] *= multiplier;  // multiplying the min value with the multiplier
        }
        return nums;
    }
};
