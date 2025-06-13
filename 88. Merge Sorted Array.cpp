class Solution {
public:
    // TC : O(n) using three pointer approach
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // pointing to the last index to store the largest among nums1, nums2
        int last = m + n - 1;
        while (m > 0 && n > 0) {
            if (nums1[m - 1] > nums2[n - 1]) {
                nums1[last] = nums1[m - 1];
                m--;
            } else {
                nums1[last] = nums2[n - 1];
                n--;
            }
            last--;
        }

        // edge case, when element still left in nums2
        // nums1 = [2,2,3,0,0,0], m = 3, nums2 = [1,5,6], n = 3
        while (n > 0) {
            nums1[last] = nums2[n - 1];
            n--;
            last--;
        }
    }
};
