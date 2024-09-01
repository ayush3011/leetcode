class Solution {
public:
    string stringHash(string s, int k) {
        string ans="";
        int n=s.size();
        
        for(int i=0; i<n; i=i+k){
            int subStringSum=0;
            for(int j=i; j<i+k; j++){
                subStringSum+=s[j]-97;
            }
            int remainder=(subStringSum%26);
            ans+=(remainder+97);
        }
        return ans;
    }
};
