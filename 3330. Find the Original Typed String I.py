class Solution:
    def possibleStringCount(self, word: str) -> int:
        ans = 0
        for i in range(0, len(word) - 1):
            if word[i + 1] == word[i]:
                ans += 1
        return ans + 1
