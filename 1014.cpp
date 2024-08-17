int maxScoreSightseeingPair(vector<int>& values) {
        // int n = values.size();
        // vector<int> dp(n, 0);

        // dp[0] = values[0];
        // int max = dp[0], pos = 0;

        // for (int i = 1; i < n; i++) {
        //     dp[i] = (values[i] + max) - (i - pos);
        //     if (values[i] >= max - (i - pos)) {
        //         max = values[i];
        //         pos = i;
        //     }
        // }

        // int ans = dp[0];
        // for (auto it : dp) {
        //     if (it > ans)
        //         ans = it;
        // }

        // return ans;

        //Solution 2

        int n=values.size();
        int best=values[0], ans=0;

        for(int j=1; j<n; j++){
            ans=max(ans, best+values[j]-j);
            best=max(best, values[j]+j);
        }

        return ans;
}
