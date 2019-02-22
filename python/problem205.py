class Solution:
    def isIsomorphic(self, s: 'str', t: 'str') -> 'bool':
        if len(set(s)) != len(set(t)):
            return False
        
        def strtoint(self,s):
            se = set()
            dic = {}
            li = []
            k = 0
            for i in range(len(s)):
                if s[i] in se:
                    li.append(dic[s[i]]) 

                else:
                    se.add(s[i])
                    dic[s[i]]= k
                    li.append(k) 
                    k+=1
            return li
        return strtoint(self,s) == strtoint(self,t)
