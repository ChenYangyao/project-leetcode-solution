import time
class Test:
    def test(self,s,repeat):
        t1=time.time()
        for i in range(repeat):
            s.isMonotonic(k)
        t2=time.time()
        print('time=',t2-t1)


class Solution:
    def isMonotonic(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        if len(A)==1:
            return True
        for i in range(len(A)-1):
                if A[i]>A[i+1]:
                    for k in range(i+1,len(A)-1):
                        if A[k]<A[k+1]:
                            return False
                    return True
                if A[i]<A[i+1]:
                    for k in range(i+1,len(A)-1):
                        if A[k]>A[k+1]:
                            return False
                    return True
                if i==len(A)-2:
                    return True
#from discuss https://leetcode.com/problems/monotonic-array/discuss/178815/Python3-3-lines
class Solution2(object):
    def isMonotonic(self, A):
        a=sorted(A)
        b=a[::-1]
        return A==a or A==b

                
if __name__ == '__main__':
    t=Test()
    s=Solution()
    s1=Solution2()
    k=[]
    for i in range(100000):
        k.append(i)
    
    t.test(s,1000)
    t.test(s1,1000)
    