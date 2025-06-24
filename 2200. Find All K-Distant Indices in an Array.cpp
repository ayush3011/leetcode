class Solution {
public:
    // Brute Force : TC - O(N∗K∗LogN)
    // vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
    //     // making a set to store only unique indices
    //     set<int> s;
    //     int n = nums.size();

    //     // iterating and finding the key
    //     for (int i = 0; i < nums.size(); i++) {
    //         int ele = nums[i];
    //         if (ele == key) { // if key found, generating all possible
    //         indices
    //                           // for the key index
    //             for (int j = 0; j <= i; j++) {
    //                 if (abs(i - j) <= k) {
    //                     s.insert(j);
    //                 }
    //             }
    //             for (int j = i; j < n; j++) {
    //                 if (abs(i - j) <= k) {
    //                     s.insert(j);
    //                 }
    //             }
    //         }
    //     }

    //     // copying the set into vector
    //     vector<int> ans(s.begin(), s.end());
    //     return ans;
    // }

    // Optimized version - TC : O(N) , Spcace : O(N)
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> result;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] == key) {
                int start = max(i - k, 0);
                int end = min(i + k, n - 1);

                // to avoid duplicates, we start from where the last element of
                // the vector has been added
                if (result.size() > 0 && result.back() >= start)
                    start = result.back() + 1;

                for (int j = start; j <= end; j++)
                    result.push_back(j);
            }
        }
        return result;
    }
};
