class Solution:
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        if not s:
            print(0)
        g.sort()
        s.sort()

        su=0

        for i in range(len(g)):

            while  s:
                if g[i]<=s[0]:
                    su+=1
                    s.pop(0)
                    break
                else:
                    s.pop(0)
        return su
