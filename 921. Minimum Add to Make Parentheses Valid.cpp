class Solution {
public:
    int minAddToMakeValid(string s) {

        int size = 0;
        int openB = 0;

        for (char c : s) {
            if (c == '(')
                size++;
            else if (c == ')') {
                if (size > 0)
                    size--;
                else
                    openB++;
            }
        }

        return size + openB;
    }
};
