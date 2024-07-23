vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto num : nums)
            m[num]++;

        sort(nums.begin(), nums.end(),
             [&](int a, int b) { return m[a] != m[b] ? m[a] < m[b] : a > b; });

        return nums;
}
