int sumOfUnique(vector<int>& nums) {
        int ans = 0, n = nums.size();
        unordered_map<int, int> m;

        for (int num : nums) {
            m[num]++;
            if (m[num] == 1) {
                ans += num;
            } else if (m[num] == 2) {
                ans -= num;
            }
        }
        return ans;
}
