class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int sz = original.size();
        if (m * n != sz)
            return {};
        int k = 0;
        vector<vector<int>> v(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                v[i][j] = original[k];
                k++;
            }
        }

        return v;
    }
};
