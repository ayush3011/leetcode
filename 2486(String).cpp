class Solution
{
public:
    int appendCharacters(string s, string t)
    {
        int ans = t.size();
        int i = 0, j = 0;
        while (i < s.size())
        {
            if (s[i] == t[j])
            {
                ans--;
                j++;
            }
            i++;
        }
        return ans;
    }
};