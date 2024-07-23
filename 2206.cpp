bool divideArray(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto num : nums)
            m[num]++;

        for (auto it : m) {
            if (it.second % 2 != 0)
                return false;
        }
        return true;
}
