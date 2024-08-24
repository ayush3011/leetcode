class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int maxEle = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxEle)
                maxEle = nums[i];
        }
        int ans = 0;
        for (int i = 0; i < k; i++) {
            ans += maxEle;
            maxEle++;
        }
        return ans;
    }
};
