class Solution {
public:
    int minLength(string s) {

        stack<char> st;
        st.push('#'); // Adding a dummy character

        for (int i = 0; i < s.size(); i++) {
            if ((st.top() == 'A' && s[i] == 'B') ||
                (st.top() == 'C' && s[i] == 'D')) {
                st.pop();
                continue;
            }
            st.push(s[i]);
        }

        return st.size() - 1; // substracting the dummy character
    }
};
