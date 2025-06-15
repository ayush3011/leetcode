class Solution {
public:
    int maxDiff(int num) {
        // coverting the number to string to iterate over it
        string str1 = to_string(num);
        string str2 = str1;

        // finding the first index that is not 9, return index else return npos
        // (no position)
        int idx1 = str1.find_first_not_of('9');
        if (idx1 != string::npos) {
            char ch = str1[idx1];
            replace(begin(str1), end(str1), ch, '9');
        }

        // minimizing str2 by keeping an eye on some of the edge cases
        for (int i = 0; i < str2.size(); i++) {
            char ch = str2[i];

            // if it is the first character that is not 1 make it one
            if (i == 0) {
                if (ch != '1') {
                    replace(begin(str2), end(str2), ch, '1');
                    break;
                }
            } else if (ch != '0' && ch != str2[0]) {
                replace(begin(str2), end(str2), ch, '0');
                break;
            }
        }
        return stoi(str1) - stoi(str2);
    }
};
