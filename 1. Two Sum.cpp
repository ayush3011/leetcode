class Solution {
public:
    // // Approach 1 : Brute force, TC: O(n^2)
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     int n = nums.size(), i, j;
    //     for (i = 0; i < n; i++) {
    //         for (j = i + 1; j < n; j++) {
    //             if ((nums[i] + nums[j]) == target)
    //                 return {i, j};
    //         }
    //     }
    //     return {};
    // }

    // Approach 2 : Optimized using map, TC: O(n)
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size(), i;
        map<int, int> m;

        for (i = 0; i < n; i++) {
            int required = target - nums[i];
            if (m.find(required) != m.end()) {
                return {m[required], i};
            }
            m[nums[i]] = i;
        }
        return {};
    }
};
