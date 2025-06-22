class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result;  // Stores the final result strings
        int n = s.size();       // Length of the input string

        int i = 0;              // Pointer to traverse the string

        // Loop through the string in chunks of size 'k'
        while (i < n) {
            // Calculate the end index 'j' for the current chunk
            // If remaining characters are less than 'k', adjust 'j' to avoid out-of-bounds
            int j = (i + k - 1) >= n ? n - 1 : i + k - 1;

            // Extract substring from index 'i' to 'j' (inclusive)
            string temp = s.substr(i, j - i + 1);

            // If extracted substring is shorter than 'k', fill the remaining with 'fill' character
            if (j - i + 1 < k) {
                int remaining = k - (j - i + 1);      // Number of characters to fill
                temp += string(remaining, fill);      // Append fill characters
            }

            // Add the chunk to the result
            result.push_back(temp);

            // Move to the next chunk
            i += k;
        }

        // Return the result vector
        return result;
    }
};
