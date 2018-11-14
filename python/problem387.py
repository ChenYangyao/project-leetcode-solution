class Solution:
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        se=set(s)
        li=[]
        for i in se:
            if s.count(i)==1:
                li.append(i)
        if li:
            return min(s.index(i) for i in li)
        else:
             return -1
        
        
        
# FROM  https://leetcode.com/problems/first-unique-character-in-a-string/discuss/193095/Python-constant-space-O(1)-and-O(n)-solution-using-inbuilt-functions       
class Solution2(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        space = [0]*26 
        ascii_a = ord('a') 
        for i in range(len(s)):
            index = ord(s[i]) - ascii_a
            space[index] += 1
        for i in range(len(s)):
            index = ord(s[i]) - ascii_a
            if space[index]==1:
                return i
        return -1