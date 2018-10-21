import time
import re
class Test:
    def test(self,s,repeat):
        t1=time.time()
        for i in range(repeat):
            s.rotatedDigits(N)
        t2=time.time()
        print('time=',t2-t1)

class Solution:
    def rotatedDigits(self, N):
        """
        :type N: int
        :rtype: int
        """
        set1={3,4,7}
        set2={0,1,8}
        cnt=0
        for i in range(1,N+1):
            if any(int(k) in set1 for k in str(i)) or all(int(k) in set2 for k in str(i)):
                cnt+=1
        return N-cnt
        
# https://leetcode.com/problems/rotated-digits/discuss/174242/Python-re               
class Solution2(object):
    def rotatedDigits(self, N):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: List[int]
        """
        count = 0
        for i in range(1,N+1):
            i = str(i)
            if re.search('[347]+', i) or re.search('[018]+',i) and not re.search('[2569]', i):
                count += 1
        return N-count


                  
                
                
if __name__ == '__main__':
    N=1008950
    s=Solution()
    s1=Solution2()
    t=Test()
    t.test(s,5)
    t.test(s1,5)