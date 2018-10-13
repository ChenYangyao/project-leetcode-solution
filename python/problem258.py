import time
class Test:
    def test(self,s,repeat):
        t1=time.time()
        for i in range(repeat):
            s.addDigits(num)
        t2=time.time()
        print('time=',t2-t1)

class Solution(object):
    def addDigits(self,num):
        """
        :type num: int
        :rtype: int
        """
        def su(num):
            s=0
            nu=str(num)
            for i in nu:
                s+=int(i)
            return s
        while num>9:
            num=su(num)
        return num
        
#from https://leetcode.com/problems/add-digits/discuss/160206/Python-1-line-beats-95
class Solution2(object):
    def addDigits(self,num):
        return self.addDigits(sum(int(i) for i in str(num))) if num>=10 else num
        
        
#from  https://leetcode.com/problems/add-digits/discuss/177126/Python-O(1Time      
class Solution3(object):
    def addDigits(self,num):
        if num==0:
            return 0
        t=num%9
        return t if t else 9

                  
                
                
if __name__ == '__main__':
    num=118567434135724316345156341561342373453434344864146427644776741646416746137925465254968756723745727357654612629452760126524762457625746
    s=Solution()
    s1=Solution2()
    s2=Solution3()
    t=Test()
    t.test(s,100000)
    t.test(s1,100000)
    t.test(s2,100000)