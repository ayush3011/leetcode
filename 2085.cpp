int countWords(vector<string>& words1, vector<string>& words2) {

        unordered_map<string, int> m1;
        unordered_map<string, int> m2;
        int ans = 0;

        for (auto it : words1)
            m1[it]++;

        for (auto it : words2)
            m2[it]++;

        for (int i = 0; i < words1.size(); i++) {
            if (m1[words1[i]] == 1 && m2[words1[i]] == 1)
                ans++;
        }

        return ans;
}
