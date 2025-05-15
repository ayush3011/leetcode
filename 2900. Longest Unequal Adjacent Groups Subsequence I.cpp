class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words,
                                         vector<int>& groups) {
        vector<string> ans;
        vector<int> altIndices;
        int checkValue = groups[0];
        altIndices.push_back(0);
        for (int i = 1; i < groups.size(); i++) {
            if (checkValue == 1 && groups[i] == 0) {
                checkValue = 0;
                altIndices.push_back(i);
            } else if (checkValue == 0 && groups[i] == 1) {
                checkValue = 1;
                altIndices.push_back(i);
            }
        }

        for (int i = 0; i < altIndices.size(); i++) {
            ans.push_back(words[altIndices[i]]);
        }
        return ans;
    }
};
