class Solution {
public:
    int minimumDeletions(string word, int k) {
        // storing the freq of all the characters
        vector<int> freq(26, 0);
        for (char& ch : word) {
            freq[ch - 'a']++;
        }

        // maximum answer 
        int result = word.length();

        // brute force the complete array for each index check other character frequency
        // maximum freq allowed for other character is freq[currentEle] to freq[currentEle + k]
        for (int i = 0; i < 26; i++) {
            int deleted = 0;
            for (int j = 0; j < 26; j++) {
                // if it is the same element
                if (j == i)
                    continue;
                
                // if freq is less, we need to delete them all
                if (freq[j] < freq[i])
                    deleted += (freq[j]);
                else if (abs(freq[j] - freq[i]) > k)
                    deleted += (freq[j] - freq[i] - k); // else only these many element need to be deleted
            }
            result = min(result, deleted);
        }

        return result;
    }
};
