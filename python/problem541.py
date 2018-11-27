class Solution:
    def reverseStr(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        li=list(s)
        for i in range(0,len(li),2*k):
            li[i:i+k]=reversed(li[i:i+k])
        return "".join(li)  