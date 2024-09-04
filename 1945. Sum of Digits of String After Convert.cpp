class Solution {
public:
    int getLucky(string s, int k) {
        int n = s.size();
        // building initial integer string out of the alphabets
        string intString = "";
        for (int i = 0; i < n; i++) {
            intString = intString + to_string(s[i] - 96);
        }

        while (k--) {
            int len = intString.size();
            int sum = 0;
            for (int i = 0; i < len; i++) {
                sum = sum + (intString[i] - '0');
            }
            intString = to_string(sum);
        }

        return stoi(intString);
    }
};
