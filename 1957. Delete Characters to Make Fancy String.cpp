class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        if (n < 3){
            return s;
        }
        string ans = "";
        for (int i = 0; i < n - 2; i++) {
            char currrentChar = s[i];
            if (s[i + 1] == currrentChar && s[i + 2] == currrentChar) {
                continue;
            } else {
                ans.push_back(currrentChar);
            }
        }
        ans.push_back(s[n - 2]);
        ans.push_back(s[n - 1]);
        return ans;
    }
};
