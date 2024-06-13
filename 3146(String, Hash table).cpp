int findPermutationDifference(string s, string t) 
{

        int ans = 0;

        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); i++)
            m[s[i]] = i;

        for (int i = 0; i < t.size(); i++) 
        {
            auto it = m.find(t[i]);
            if (it != m.end())
                ans += abs(it->second - i);
        }

        return ans;
}
