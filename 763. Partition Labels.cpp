class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        int start = 0, end = 0, i = 0;

        // storing the last index of the characters
        vector<int> mp(26, -1);
        for (i = 0; i < n; i++) {
            mp[s[i] - 'a'] = i;
        }

        // result vector for storing the partitions
        vector<int> result;
        i = 0;
        while (i < n) {
            end = max(end, mp[s[i] - 'a']);
            if (i == end) {
                result.push_back(end - start + 1);
                start = end + 1;
            }
            i++;
        }

        return result;
    }
};
