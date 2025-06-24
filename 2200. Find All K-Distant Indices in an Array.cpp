class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        // making a set to store only unique indices
        set<int> s;
        int n = nums.size();

        // iterating and finding the key
        for (int i = 0; i < nums.size(); i++) {
            int ele = nums[i];
            if (ele == key) { // if key found, generating all possible indices
                              // for the key index
                for (int j = 0; j <= i; j++) {
                    if (abs(i - j) <= k) {
                        s.insert(j);
                    }
                }
                for (int j = i; j < n; j++) {
                    if (abs(i - j) <= k) {
                        s.insert(j);
                    }
                }
            }
        }

        // copying the set into vector
        vector<int> ans(s.begin(), s.end());
        return ans;
    }
};
