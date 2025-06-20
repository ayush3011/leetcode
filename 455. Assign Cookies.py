class Solution:
    # using two pointer approach TC : O(nlogn)
    # giving the smallest greedy children the smallest possible cookie
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()
        contentChildren = 0
        cookieIndex = 0

        while(contentChildren<len(g) and cookieIndex<len(s)):
            if(s[cookieIndex]>=g[contentChildren]):
                contentChildren+=1
            cookieIndex+=1
        
        return contentChildren
        
