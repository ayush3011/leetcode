class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        int maxEle = 0, maxEleCount = 0;
        for (int a : nums) {
            maxEle = max(maxEle, a);
        }

        int i = 0, j = 0, n=nums.size();

        while (j < n) {
            if (nums[j] == maxEle) {
                maxEleCount++;
            }
            while (maxEleCount == k) {
                ans += (n - j );
                if (nums[i] == maxEle) {
                    maxEleCount--;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};
