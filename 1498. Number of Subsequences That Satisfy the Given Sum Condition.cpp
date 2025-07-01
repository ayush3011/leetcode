class Solution {
public:
    // using two pointer approach
    int M = 1e9 + 7;
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        int result = 0;

        // sorting because we are only concerned with elements and not order
        sort(nums.begin(), nums.end());

        // precomputing powers of 2 to escape TLE
        vector<int> power2(n);
        power2[0] = 1;
        for (int i = 1; i < n; i++) {
            power2[i] =
                (power2[i - 1] * 2LL) % M; // saving intermediate overflow
        }

        while (l <= r) {
            // if left and right together are <= target then all elements in
            // between would also be
            if (nums[l] + nums[r] <= target) {
                result = (result + power2[r - l]) % M;
                l++;
            } else { // else decreasing the right pointer towards a smaller
                     // element
                r--;
            }
        }

        return result;
    }
};
