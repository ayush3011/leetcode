class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0, balanced = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'R')
                balanced--;
            else if (s[i] == 'L')
                balanced++;
            if (balanced == 0)
                ans++;
        }

        return ans;
    }
};
