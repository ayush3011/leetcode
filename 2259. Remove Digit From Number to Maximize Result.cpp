class Solution {
public:
    string removeDigit(string number, char digit) {
        // Assigning the answer as an empty string
        string ans = "";
        for (int i = 0; i < number.size(); i++) {
            string temp;
            if (number[i] == digit) {
                temp = number;
                temp.erase(
                    i, 1); // erasing the number and keeping the string entact
                if (temp >
                    ans) { // lexicographical string comparison instead of stoi
                    ans = temp;
                }
            }
        }
        return ans;
    }
};
