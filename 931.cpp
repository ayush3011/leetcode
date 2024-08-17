int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            dp[0][i] = matrix[0][i];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int minPrev = dp[i - 1][j]; // directly above
                if (j > 0)
                    minPrev = min(minPrev, dp[i - 1][j - 1]);
                if (j < n - 1)
                    minPrev = min(minPrev, dp[i - 1][j + 1]);
                dp[i][j] = matrix[i][j] + minPrev;
            }
        }

        int ans = INT32_MAX;
        for (int i = 0; i < n; i++) {
            if (dp[n - 1][i] < ans)
                ans = dp[n - 1][i];
        }

        return ans;
}
