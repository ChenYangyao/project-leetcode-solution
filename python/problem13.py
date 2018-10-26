import time
class Test:
    def test(self,c,repeat):
        t1=time.time()
        for i in range(repeat):
            c.romanToInt(s)
        t2=time.time()
        print('time=',t2-t1)


class Solution:
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        dic={'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
        n=0
        for i in s:
            n+=dic[i]
        if 'IV' in s or 'IX' in s:
            n-=2
        if 'XL' in s or 'XC' in s:
            n-=20
        if 'CD' in s or 'CM' in s:
            n-=200
        return n
        
#FROM https://leetcode.com/problems/roman-to-integer/discuss/181220/Python-Solution-How-can-it-become-even-better     
class Solution2(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        rom_to_int = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        result = 0
        num = 3999
        for l in s:
            t = rom_to_int[l]
            if t <= num:
                num = t
            else:
                num = -2 * num + t
            result += num
        return result

      
        
if __name__ == '__main__':
    s='MMMMCMXCIV'
    c=Solution()
    c1=Solution2()
    t=Test()
    t.test(c,5000000)
    t.test(c1,5000000)
