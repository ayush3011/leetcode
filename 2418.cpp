vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string> ans;
        map<int, string, greater<int>> m;
        int n = heights.size();

        for (int i = 0; i < n; i++) {
            m[heights[i]] = names[i];
        }
        for (auto it : m) {
            ans.push_back(it.second);
        }
        return ans;
}
