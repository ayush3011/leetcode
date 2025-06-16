class Solution {
public:
    // // Brute Force : TC --> O(n^2)
    // int maximumDifference(vector<int>& nums) {
    //     // Assigning initial value to diff
    //     int diff = -1;
    //     for (int i = 0; i < nums.size(); i++) {
    //         for (int j = i + 1; j < nums.size(); j++) {
    //             if (nums[j] > nums[i]) {
    //                 int currentDiff = nums[j] - nums[i];
    //                 diff = max(diff, currentDiff);
    //             }
    //         }
    //     }
    //     return diff;
    // }

    // Method 2 : TC --> O(n)
    int maximumDifference(vector<int>& nums) {
        int diff = -1;
        int minEle = nums[0]; // Assuming first element is the min value
        for (int j = 1; j < nums.size(); j++) {
            int currEle = nums[j];
            if (currEle > minEle) { // if current element is greater than min
                                    // element, we check their diff
                diff = max(diff, nums[j] - minEle);
            } else { // else update the curr element to be the minimum element
                minEle = currEle;
            }
        }
        return diff;
    }
};
