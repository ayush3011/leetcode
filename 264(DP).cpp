int nthUglyNumber(int n) {
        vector<int> ans;
        ans.push_back(1);
        int two = 0, three = 0, five = 0;

        while (ans.size() < n) {
            ans.push_back(
                min(ans[two] * 2, min(ans[three] * 3, ans[five] * 5)));
            if (ans.back() == ans[two] * 2)
                two++;
            if (ans.back() == ans[three] * 3)
                three++;
            if (ans.back() == ans[five] * 5)
                five++;
        }
        return ans.back();
}
