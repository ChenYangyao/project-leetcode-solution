class Solution:
    def wordPattern(self, pattern: str, str: str) -> bool:
        li = str.split(' ')
        if len(pattern) != len(li):
            return False
        if len(set(pattern)) != len(set(li)):
            return False
        dic={}
        for i in range(len(li)):
            if pattern[i] in dic and dic[pattern[i]] != li[i]:
                return False
            else:
                dic[pattern[i]] = li[i]
        
        return True


# https://leetcode.com/problems/word-pattern/discuss/237978/Python-4-Lines-easy-99.9        
class Solution:
    def wordPattern(self, pattern: 'str', str: 'str') -> 'bool':
        l = str.split()
        if len(pattern) != len(l):
            return False
        return len(set(zip(pattern, l))) == len(set(pattern)) == len(set(l))