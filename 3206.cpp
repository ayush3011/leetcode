int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            int l = i;
            int m = (i + 1) % n;
            int r = (i + 2) % n;
            if(colors[m] != colors[l] && colors[m] != colors[r]) {
                ans++;
            }
        }

        return ans;
}
