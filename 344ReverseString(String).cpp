class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int len = s.size();

        int i = 0, j = len - 1;

        while (i <= j)
        {
            char temp = s[j];
            s[j] = s[i];
            s[i] = temp;
            i++;
            j--;
        }
    }
};