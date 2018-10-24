import time
class Test:
    def test(self,c,repeat):
        t1=time.time()
        for i in range(repeat):
            c.titleToNumber(s)
        t2=time.time()
        print('time=',t2-t1)


class Solution:
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        cnt=0
        dic={chr(i):(i-64) for i in range(65,91)} #EXTRA SPACE ADN TIME
        for i in range(len(s)):
            cnt+=pow(26,len(s)-i-1)*dic[s[i]]
        return cnt
        
#FROM https://leetcode.com/problems/excel-sheet-column-number/discuss/183353/Easy-python-beats-100       
class Solution2(object):
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        result = 0
        s=s[::-1]
        for idx, val in enumerate(s):
            result += 26**idx * (ord(val)-ord('A')+1) 
            
        return result
        
if __name__ == '__main__':
    s='FHSDGJKGHDFKHJODSHGIRTHGSDFIOGHDFKHGDFKBHNKLFDKLENH'
    c=Solution()
    c1=Solution2()
    t=Test()
    t.test(c,100000)
    t.test(c1,100000)