class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<bool> temp(n * n, false);
        int repeated;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (temp[grid[i][j] - 1] == true) {
                    repeated = grid[i][j];
                    continue;
                }
                temp[grid[i][j] - 1] = !temp[grid[i][j] - 1];
            }
        }

        vector<int> res(2);
        res[0] = repeated;
        for (int i = 0; i < n * n; i++) {
            if (temp[i] == false) {
                res[1] = i + 1;
            }
        }

        return res;
    }
};
