#include<bits/stdc++.h>
using namespace std;

int longestPalindrome(string s) 
{
        unordered_map<char, int> m;

        for(auto it:s)
            m[it]++;

        int ans=0;
        bool has_odd=false;

        for(auto it:m)
        {
            if((it.second)%2==0)
                ans+=it.second;
            else
            {
                ans+=it.second-1;
                has_odd=true;
            }  
        }
        if(has_odd)
            return ans+1;
        else
            return ans;
}

int main()
{
  cout<<longestPalindrome("abccccdd");
  return 0;
}
