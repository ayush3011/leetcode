class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int Ones = 0;
        int i, n = s.size();
        
        // Count the number of '1's in the string
        for (i = 0; i < n; i++) {
            if (s[i] == '1') Ones++;
        }

        // Set the first (Ones - 1) positions in the string to '1'
        i = 0;
        while (Ones > 1) {
            s[i] = '1';
            i++;
            Ones--;
        }
        
        // Set the remaining positions except the last one to '0'
        while (i < n - 1) {
            s[i] = '0';
            i++;
        }
        
        // Set the last position to '1' to make the number odd
        s[n - 1] = '1';
        
        return s;
    }
};
