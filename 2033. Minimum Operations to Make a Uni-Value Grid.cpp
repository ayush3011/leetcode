class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> v;
        for (auto row : grid) {
            for (auto ele : row) {
                v.push_back(ele);
            }
        }
        sort(v.begin(), v.end());
        int median = v[v.size() / 2];

        int operations = 0;

        for (auto num : v) {
            int diff = abs(median - num);
            if (diff % x != 0)
                return -1;
            operations += diff / x;
        }

        return operations;
    }
};
