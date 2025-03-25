class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        // result vector for storing merged intervals
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());
        result.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= result.back()[1]) {
                result.back()[0] = min(result.back()[0], intervals[i][0]); // This line is optional since intervals is already sorted
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            } else {
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};
