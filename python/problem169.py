import random
import time
class Test:
    def test(self,c,repeat):
        t1=time.time()
        for i in range(repeat):
            c.majorityElement(s)
        t2=time.time()
        print('time=',t2-t1)




class Solution:
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l=len(nums)//2
        dic={}
        for k in nums:
            dic.setdefault(k, 0)
            dic[k]+=1
        for i in dic:
            if dic[i]>=l:
                return i
                
                
class Solution2:
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l=len(nums)//2
        dic={}
        for k in nums:
            dic.setdefault(k, l)
            dic[k]-=1
            if dic[k]==0:
                return k
                
                
if __name__ == '__main__':
    s=[random.randint(1,2) for i in range(100001)]
    c=Solution()
    c1=Solution2()
    t=Test()
    t.test(c,100)
    t.test(c1,100)