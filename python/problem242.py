class Solution:
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        dic={}
        for i in s:
            dic.setdefault(i, 0)
            dic[i]+=1
        for i in t:
            if not i in dic:
                return False
            dic[i]-=1
        for i in dic:
            if dic[i]!=0:
                return False
        return True


class Solution2:
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        ss=sorted(s)
        st=sorted(t)
        return ss==st        
#from    https://leetcode.com/problems/valid-anagram/discuss/185596/6-lines-easy-to-understand-python-code-using-set-beat-94%2B     
class Solution3:
    def isAnagram(self, s, t):
        if set(s)!= set(t):
            return False
        for c in set(s):
            if s.count(c) != t.count(c):
                return False
        return True