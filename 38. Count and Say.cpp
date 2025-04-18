class Solution {
public:
    // helper function to generate string one after the another from previous
    // string
    string helper(string s) {
        int n = s.size();
        string generated_string = "";

        // iterating through the whole string
        for (int i = 0; i < n;) {
            char current = s[i]; // fixing current character to count it;
            int count = 0;
            while (s[i] == current) {
                count++;
                i++;
            }
            generated_string = generated_string + to_string(count) + current;
            count = 0;
        }
        return generated_string;
    }

    string countAndSay(int n) {
        string ans = "1"; // default case
        if (n == 1)
            return "1";
        for (int i = 2; i <= n; i++) {
            ans = helper(
                ans); // calling helper function with the current generated ans
        }
        return ans;
    }
};
