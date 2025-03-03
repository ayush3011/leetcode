class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> smaller, greater;

        // Collect numbers in respective buckets
        for (int num : nums) {
            if (num < pivot) {
                smaller.push_back(num);
            } else if (num > pivot) {
                greater.push_back(num);
            }
        }

        // Count occurrences of pivot
        int pivotElements = nums.size() - (smaller.size() + greater.size());

        // Construct result
        vector<int> result;
        result.insert(result.end(), smaller.begin(), smaller.end());
        result.insert(result.end(), pivotElements, pivot);
        result.insert(result.end(), greater.begin(), greater.end());

        return result;
    }
};
