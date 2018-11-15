class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        se=set(s)
        su=0
        t=0
        for i in se:
            c=s.count(i)
            if c%2==0:
                su+=c
                continue
            else:
                su+=c-1
                t+=1
        if t>0:
            return su+1
        return su

# from https://leetcode.com/problems/longest-palindrome/discuss/191708/python-2-lines  
class Solution2:
    def longestPalindrome(self, s):
        c=collections.Counter(s).values()
        return any(x%2 for x in c)+sum(x//2*2 for x in c)   