vector<string> commonChars(vector<string> &words)
{
    vector<int> globalFreq(26, 101);

    for (string word : words)
    {
        vector<int> tempFreq(26, 0);
        for (char ch : word)
            tempFreq[ch - 'a']++; // converting charater to index
        for (int i = 0; i < 26; i++)
            globalFreq[i] = min(globalFreq[i], tempFreq[i]);
    }

    vector<string> ans;
    for (int i = 0; i < 26; i++)
    {
        while (globalFreq[i] > 0)
        {
            ans.push_back(string(1, 'a' + i)); // converting index back to character
            globalFreq[i]--;
        }
    }
    return ans;
}
