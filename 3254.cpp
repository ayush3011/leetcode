vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i <= n - k; i++) { 
            bool valid = true;

            
            for (int ele = i + 1; ele < i + k; ele++) {
                if (nums[ele - 1] >= nums[ele] || nums[ele] != nums[ele - 1] + 1) {
                    valid = false;
                    break;
                }
            }

            
            if (valid) {
                int maxEle = *max_element(nums.begin() + i, nums.begin() + i + k);
                ans.push_back(maxEle);
            } else {
                ans.push_back(-1);
            }
        }
        return ans;
}
