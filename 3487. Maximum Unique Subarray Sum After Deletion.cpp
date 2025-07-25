class Solution {
public:
    int maxElement(vector<int> arr) {

        int ans = INT_MIN;
        for (int num : arr) {
            if (num > ans) {
                ans = max(ans, num);
            }
        }
        return ans;
    }
    int maxSum(vector<int>& nums) {

        int ans = maxElement(nums);
        if (ans <= 0)
            return ans;

        ans = 0;
        set<int> s;
        for (int num : nums) {
            if (num >= 0) {
                s.insert(num);
            }
        }

        for (auto num : s) {
            ans += num;
        }
        return ans;
    }
};
