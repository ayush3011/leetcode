class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxCount = 0;
        int n = s.size();
        int i = 0, j = 0;
        unordered_map<char, int> m;

        while (j < n) {
            m[s[j]]++;
            while (m[s[j]] > 1) {
                m[s[i]]--;
                i++;
            }
            // maxCount should be outside so it all the characters are unique the second while loop does not run
            maxCount = max(maxCount, j - i + 1); 
            j++;
        }

        return maxCount;
    }
};
