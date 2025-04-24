class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int ans = 0;
        set<int> s(nums.begin(), nums.end());
        int uniqueCount = s.size();

        unordered_map<int, int> m;

        int i = 0, j = 0, n = nums.size();

        while (j < n) {
            m[nums[j]]++;
            while (m.size() == uniqueCount) {
                ans += (n - j);
                m[nums[i]]--;
                if (m[nums[i]] == 0)
                    m.erase(nums[i]);
                i++;
            }
            j++;
        }

        return ans;
    }
};
