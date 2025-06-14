class Solution {
public:
    int minMaxDifference(int num) {
        string str1 = to_string(num);
        string str2 = str1;

        // gives index of first character that is not '9' else gives npos
        int idx = str1.find_first_not_of('9');
        if (idx != string::npos) {
            char ch = str1[idx];
            replace(begin(str1), end(str1), ch, '9');
        }

        // since input is an integer without leading zeros
        char ch = str2[0];
        replace(begin(str2), end(str2), ch, '0');

        // string to integer --> stoi
        return stoi(str1) - stoi(str2);
    }
};
