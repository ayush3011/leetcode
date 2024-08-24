class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m; // map to store the char and index
        int ans=-1;
        for(int i=0; i<s.size(); i++){
            if(m.find(s[i])!=m.end()){
                ans=m[s[i]];
                break;
            }
            m[s[i]]=i;
        }
        return ans;;
    }
};
