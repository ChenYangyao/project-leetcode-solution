# from  solution
class Solution:
    def isValid(self, s: str) -> bool:
        if len(s)%2 != 0:
            return False
        dic = {'}':'{', ']':'[', ')':'(' }
        li = []
        for i in s:
            if i in dic:
                if not li or li.pop() != dic[i]:
                    return False
            else:
                li.append(i)
        
        if li:
            return False
        else:
            return True