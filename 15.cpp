class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();

        // Sort the nums array to use the two-pointer approach
        sort(nums.begin(), nums.end());

        // Fixing the first number n1
        for (int i = 0; i < n - 2; i++) {
            // Avoid duplicates for the first number
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int n1 = nums[i];
            int target = -n1;
            int left = i + 1;
            int right = n - 1;

            // Two-pointer approach to find n2 and n3
            while (left < right) {
                int sum = nums[left] + nums[right];

                if (sum == target) {
                    result.push_back({n1, nums[left], nums[right]});

                    // Move left pointer to the right, avoiding duplicates
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }

                    // Move right pointer to the left, avoiding duplicates
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }

                    // Move both pointers inward
                    left++;
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return result;
    }
};
